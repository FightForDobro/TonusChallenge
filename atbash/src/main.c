#include "library.h"

int main(int argc, char **argv)
{

    if (argc != 2) raise_error();


//    decode("Vg gf, Yifgv?\n"
//           "Gsv xrksvi rh mznvw uli gsv Ilnzm xlnnzmwvi Tfb Qforfh Xzvhzi, dsl fhvw rg uli\n"
//           "hvxivg xliivhklmwvmxv drgs srh tvmvizoh.\n"
//           "Gsv xrksvi yvolmth gl gsv tilfk lu hl-xzoovw hrmtov-zokszyvgrxzo drowxziw xrksvih.\n"
//           "Dsvm fhrmt gsv xrksvih lu gsrh tilfk, vzxs xszizxgvi lu gsv kozrmgvcg rh ivkozxvw\n"
//           "yb z xvigzrm xszizxgvi urcvw rm gsrh pvb lu gsv hznv zokszyvg.\n"
//           "Pvb hvovxgrlm nvgslwh nzb ezib. Gsv pvb rm Xzvhzi'h xrksvi rh zm ziyrgizib mfnyvi 'p',\n"
//           "hvovxgvw rm gsv izmtv uiln lmv gl gdvmgb-urev. Vzxs ovggvi lu gsv kozrmgvcg rh ivkozxvw\n"
//           "yb z ovggvi gszg rh 'p' xszizxgvih ufigsvi gszm rg rh rm gsv zokszyvg.");
    decode(argv[1]);
    return 0;
}
