#include <iostream>
#define CPPHTTPLIB_OPENSSL_SUPPORT
#include "httplib.h"
#include "json.hpp"

using json = nlohmann::json;

int main() {
    httplib::Client cli("https://fantasy.premierleague.com");

    // Obtener datos de bootstrap
    auto res_bootstrap = cli.Get("/api/bootstrap-static/");
    if (res_bootstrap && res_bootstrap->status == 200) {
        auto datos_bootstrap = json::parse(res_bootstrap->body);
        //Procesar los datos de bootstrap
        std::cout << "Datos bootstrap recibidos" << std::endl;
        std::cout << "Imprimiendo informacion de ejemplo: " << datos_bootstrap["events"][0] << std::endl;
    } else {
        std::cerr << "Error al obtener datos de bootstrap" << std::endl;
        if (res_bootstrap) {
            std::cerr << "Código de estado: " << res_bootstrap->status << std::endl;
        }
    }

    //Obtener Datos de Fixtures
    auto res_fixtures = cli.Get("/api/fixtures/");
    if (res_fixtures && res_fixtures->status == 200) {
        auto datos_fixtures = json::parse(res_fixtures->body);
        //Procesar los datos de fixtures
        std::cout << "Datos fixtures recibidos" << std::endl;
        std::cout << "Imprimiendo informacion de ejemplo: " << datos_fixtures[0] << std::endl;
    } else {
        std::cerr << "Error al obtener datos de fixtures" << std::endl;
        if (res_fixtures) {
            std::cerr << "Código de estado: " << res_fixtures->status << std::endl;
        }
    }

    return 0;
}