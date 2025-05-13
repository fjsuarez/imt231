#pragma once
/*
 * dataset_csv.hpp ── tiny CSV-based dataset loader
 * ------------------------------------------------
 * The CSV file must contain one sample per line:
 *
 *     absolute/or/relative/path/to/img.jpg ; label_id
 *
 * • Any leading/trailing whitespace is ignored.
 * • Lines that start with '#' are treated as comments.
 * • Paths can be absolute or relative to the CSV file’s folder.
 *
 * The header exposes:
 *   - ImageEntry   (filename + integer label)
 *   - read_csv_list(csv_path, delimiter)          → std::vector<ImageEntry>
 *   - CSVDataset   (Torch-C++ dataset wrapper)
 */

#include <string>
#include <vector>
#include <opencv2/core.hpp>
#include <torch/torch.h>

/* ------------------------------------------------------------------ */
struct ImageEntry {
    std::string path;
    int         label;
};

/** Parse CSV file and return the list of images + labels. */
std::vector<ImageEntry>
read_csv_list(const std::string& csv_file,
              char               delimiter = ';');

/* ------------------------------------------------------------------ */
/** Torch-C++ Dataset that on-the-fly converts each sample to a
 *  normalised NCHW float32 tensor in RGB colour-space.
 */
class CSVDataset : public torch::data::datasets::Dataset<CSVDataset>
{
public:
    /** Constructor
     *  @param csv_file      CSV file path.
     *  @param delimiter     Field delimiter (default ';').
     *  @param edge_len      Output side length after resize (112, 224, …).
     *  @param convert_gray  If true, images are loaded in GRAY and output
     *                       tensors have shape (1,H,W); otherwise RGB (3,H,W).
     */
    explicit CSVDataset(const std::string& csv_file,
                        char               delimiter    = ';',
                        int                edge_len     = 112,
                        bool               convert_gray = false);

    /** torch::data::Dataset API */
    torch::data::Example<> get(size_t index) override;
    torch::optional<size_t> size() const override { return entries_.size(); }

private:
    std::vector<ImageEntry> entries_;
    int                     edge_len_;
    bool                    gray_;
};
