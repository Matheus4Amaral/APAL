class Utilitaria {
    public:
        enum Cor {
            RESET,
            BLACK = 30,
            RED,
            GREEN,
            YELLOW,
            BLUE,
            MAGENTA,
            CYAN,
            WHITE
        };

        enum Efeito {
            REGULAR,
            BOLD,
            ITALIC = 3,
            UNDERLINE,
            REVERSE = 7,
            INVISIBLE
        };

        static void aguardar(int milisegundos);
        static void colorir(Efeito e, Cor c);
        static void resetarCor();
        static void limparTela();
};
