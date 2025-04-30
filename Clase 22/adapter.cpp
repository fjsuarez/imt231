#include <iostream>
#include <memory>
#include <string>

using namespace std;

class ReproductorMedia { // codigo existente
    public:
        virtual void reproducir(const string& tipoArchivo, const string& archivo) = 0;
        virtual ~ReproductorMedia() = default;
};

class ReproductorAvanzado { // codigo nuevo
    public:
        virtual void reproducirMp4(const string& archivo) = 0;
        virtual void reproducirVlc(const string& archivo) = 0;
        virtual ~ReproductorAvanzado() = default;
};

class ReproductorMp4 : public ReproductorAvanzado { // implementacion de nueva funcionalidad
    public:
        void reproducirMp4(const string& archivo) override {
            cout << "Reproduciendo archivo MP4: " << archivo << endl;
        }
        
        void reproducirVlc(const string& archivo) override {
            // No hacer nada
        }
};

class ReproductorVlc : public ReproductorAvanzado { // implementacion de nueva funcionalidad
    public:
        void reproducirMp4(const string& archivo) override {
            // No hacer nada
        }
        
        void reproducirVlc(const string& archivo) override {
            cout << "Reproduciendo archivo VLC: " << archivo << endl;
        }
};

class AdaptadorMedia : public ReproductorMedia { // adaptador
    private:
        unique_ptr<ReproductorAvanzado> reproductorAvanzado;
    
    public:
        AdaptadorMedia(const string& tipoArchivo) {
            if (tipoArchivo == "mp4") {
                reproductorAvanzado = make_unique<ReproductorMp4>();
            } else if (tipoArchivo == "vlc") {
                reproductorAvanzado = make_unique<ReproductorVlc>();
            }
        }

        void reproducir(const string& tipoArchivo, const string& archivo) override {
            if (tipoArchivo == "mp4") {
                reproductorAvanzado->reproducirMp4(archivo);
            } else if (tipoArchivo == "vlc") {
                reproductorAvanzado->reproducirVlc(archivo);
            }
        }
};


class ReproductorAudio : public ReproductorMedia {
    public:
        void reproducir(const string& tipoArchivo, const string& archivo) override {
            if (tipoArchivo == "mp3") {
                cout << "Reproduciendo archivo MP3: " << archivo << endl;
            } else if (tipoArchivo == "wav") {
                cout << "Reproduciendo archivo WAV: " << archivo << endl;
            } else if (tipoArchivo == "mp4" || tipoArchivo == "vlc") {
                // Con patrón de diseño adaptador
                AdaptadorMedia adaptador(tipoArchivo);
                adaptador.reproducir(tipoArchivo, archivo);

            } else {
                cout << "Formato de archivo no soportado: " << tipoArchivo << endl;
            }
        }
};

int main() {
    ReproductorAudio reproductor;
    // Sin patron de diseño adaptador
    // ReproductorMp4 reproductorMp4;
    // ReproductorVlc reproductorVlc;
    
    // string nombreArchivo;
    // cout << "Ingrese el nombre del archivo: ";
    // cin >> nombreArchivo;
    // cout << "Ingrese el tipo de archivo (mp3, wav, mp4, vlc): ";
    // string tipoArchivo;
    // cin >> tipoArchivo;

    // // if (tipoArchivo == "mp3" || tipoArchivo == "wav") {
    // //     reproductor.reproducir(tipoArchivo, nombreArchivo);
    // // } else if (tipoArchivo == "mp4") {
    // //     reproductorMp4.reproducirMp4(nombreArchivo);
    // // } else if (tipoArchivo == "vlc") {
    // //     reproductorVlc.reproducirVlc(nombreArchivo);
    // // } else {
    // //     cout << "Formato de archivo no soportado: " << tipoArchivo << endl;
    // // }

    reproductor.reproducir("mp3", "cancion.mp3"); // incluido
    reproductor.reproducir("wav", "sonido.wav"); // incluido
    reproductor.reproducir("mp4", "video.mp4"); // via adaptador
    reproductor.reproducir("vlc", "pelicula.vlc"); // via adaptador
    reproductor.reproducir("avi", "video.avi"); // no soportado

    return 0;
}