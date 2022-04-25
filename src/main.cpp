#include <cstdint>
#include <iostream>
#include <unistd.h>
#include <g15daemon_client.h>
#include <libg15render.h>

int32_t main(int32_t argc, char *argv[]) {
    if (argc < 2) {
        std::cout << "Usage: ./g15top <path to theme>" << std::endl;
        return -1;
    }

    auto splash = std::string(argv[1]) + "/theme.wbmp";

    auto screen = new_g15_screen(G15_G15RBUF);
    if (screen < 0) {
        printf("Error!");
        return -1;
    }

    g15canvas canvas;
    g15r_initCanvas(&canvas);
    g15r_clearScreen(&canvas, G15_COLOR_WHITE);

    g15r_loadWbmpSplash(&canvas, (char*) splash.c_str());
    g15_send(screen, reinterpret_cast<char*>(canvas.buffer), G15_BUFFER_LEN);

    while (true) {}

    close(screen);
}
