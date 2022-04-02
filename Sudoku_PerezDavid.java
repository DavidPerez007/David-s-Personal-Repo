// Nombre: David Leobardo Pérez Cruz
// Fecha: 14/02/2022
// Descripción: Algoritmo que genera un sudoku 9x9 con valores aleatorios y verifica por
// filas, columnas y grids 3x3 que se hayan cumplido las reglas del sudoku, es decir, que ningún número se repita
//en esas condiciones, además se muestra si el sudoku generado es válido o no bajo las reglas del juego sudoku.

public class Sudoku_PerezDavid {

    final static int DIMENSION = 9;

    public static void main(String[] args) {

        int sudoku[][] = new int[DIMENSION][DIMENSION];

        Rellenar_Matriz(sudoku);

        int Cantidad_Filas_Validas = Validar_Filas(sudoku);
        int Cantidad_Columnas_Validas = Validar_Columnas(sudoku);
        int Cantidad_Grids_Validos = Validar_Grids(sudoku);

        boolean Comprobar_Sudoku;
        Comprobar_Sudoku = Es_Sudoku(Cantidad_Filas_Validas, Cantidad_Columnas_Validas, Cantidad_Grids_Validos);
        Printar_Es_Sudoku(Comprobar_Sudoku);

    } // public static void

    static void Printar_Es_Sudoku(boolean Comprobacion_Es_Sudoku) {
        if (Comprobacion_Es_Sudoku == true) {
            System.out.println("El sudoku cumple todas las condiciones, por lo tanto el sudoku es válido");
        } else {
            System.out.println("El sudoku no cumple todas las condiciones, por lo tanto el sudoku no es válido");
        }
    }

    static boolean Es_Sudoku(int Filas_Validas, int Columnas_Validas, int Grids_Validos) {
        boolean Sudoku_Valido = false;
        if (Filas_Validas == 9 && Columnas_Validas == 9 && Grids_Validos == 9) {
            Sudoku_Valido = true;
        }
        return Sudoku_Valido;
    }

    static void Rellenar_Matriz(int Sudoku[][]) {
        // Ciclo para rellenar la matriz de números random
        int filas, columnas;
        int min = 1;
        int max = 9;
        for (filas = 0; filas < DIMENSION; filas++) {
            if (filas == 3 || filas == 6) {
                for (columnas = 0; columnas < DIMENSION + 5; columnas++) {
                    System.out.print("_" + " ");
                }
                System.out.println(" ");
            }

            for (columnas = 0; columnas < DIMENSION; columnas++) {
                if (columnas == 3 || columnas == 6) {
                    System.out.print("|");
                }

                int randomnumber = (int) (Math.random() * max + min);
                Sudoku[filas][columnas] = randomnumber;
                System.out.print(Sudoku[filas][columnas] + "  ");

            }
            System.out.println("  ");

        }
    }

    static int Validar_Filas(int sudoku[][]) {
        int filas, columnas, comprobador_filas = 1, filas_validas = 0;
        for (filas = 0; filas < DIMENSION; filas++) {
            for (columnas = 0; columnas < DIMENSION; columnas++) {
                if (sudoku[filas][columnas] == comprobador_filas) {
                    columnas = -1;
                    comprobador_filas++;
                }
                if (comprobador_filas == 10) {
                    filas_validas++;
                    columnas = 10;
                }
            }
            comprobador_filas = 1;

        }

        if (filas_validas == 9) {
            System.out.println("Las 9 filas son válidas");
        } else {
            System.out.println("Solo hay : " + filas_validas + " filas válidas");
        }

        return filas_validas;

    }

    static int Validar_Columnas(int Sudoku[][]) {
        int filas, columnas, comprobador_columnas = 1, columnas_validas = 0;

        for (columnas = 0; columnas < DIMENSION; columnas++) {
            for (filas = 0; filas < DIMENSION; filas++) {
                if (Sudoku[filas][columnas] == comprobador_columnas) {
                    filas = -1;
                    comprobador_columnas++;
                }
                if (comprobador_columnas == 10) {
                    columnas_validas++;
                    filas = 10;
                }
            }
            comprobador_columnas = 1;
        }
        if (columnas_validas == 9) {
            System.out.println("Las 9 filas son válidas");
        } else {
            System.out.println("Solo hay : " + columnas_validas + " filas válidas");
        }

        return columnas_validas;

    }

    static int Validar_Grids(int Sudoku[][]) {
        // ---------- VALIDAR GRIDS 3X3 -------------
        int filas, columnas;
        int contador_grids_validos = 0;
        // GRID 1
        int elemento = 0, comparador;
        int grid[] = new int[10];
        for (filas = 0; filas <= 2; filas++) {
            for (columnas = 0; columnas <= 2; columnas++) {
                grid[elemento] = Sudoku[filas][columnas];
                elemento++;
                if (elemento == 10) {
                    break;
                }

            }
        }

        int primer_elemento, segundo_elemento, grid_valido = 1;

        for (comparador = 0; comparador < 9; comparador++) {
            primer_elemento = grid[comparador];

            for (elemento = comparador; elemento < 9; elemento++) {
                segundo_elemento = grid[elemento + 1];
                if (primer_elemento == segundo_elemento) {
                    grid_valido = 0;
                }

            }
        }
        if (grid_valido == 1) {
            contador_grids_validos = contador_grids_validos + 1;
        }

        // GRID 2

        elemento = 0;
        for (filas = 0; filas <= 2; filas++) {
            for (columnas = 3; columnas <= 5; columnas++) {
                grid[elemento] = Sudoku[filas][columnas];
                elemento++;
                if (elemento == 10) {
                    break;
                }

            }
        }

        grid_valido = 1;

        for (comparador = 0; comparador < 9; comparador++) {
            primer_elemento = grid[comparador];

            for (elemento = comparador; elemento < 9; elemento++) {
                segundo_elemento = grid[elemento + 1];
                if (primer_elemento == segundo_elemento) {
                    grid_valido = 0;
                }

            }
        }
        if (grid_valido == 1) {
            contador_grids_validos = contador_grids_validos + 1;
        }

        // GRID 3

        elemento = 0;
        for (filas = 0; filas <= 8; filas++) {
            for (columnas = 6; columnas <= 5; columnas++) {
                grid[elemento] = Sudoku[filas][columnas];
                elemento++;
                if (elemento == 10) {
                    break;
                }

            }
        }

        grid_valido = 1;

        for (comparador = 0; comparador < 9; comparador++) {
            primer_elemento = grid[comparador];

            for (elemento = comparador; elemento < 9; elemento++) {
                segundo_elemento = grid[elemento + 1];
                if (primer_elemento == segundo_elemento) {
                    grid_valido = 0;
                }

            }
        }
        if (grid_valido == 1) {
            contador_grids_validos = contador_grids_validos + 1;

        }

        // GRID 4

        elemento = 0;
        for (filas = 3; filas <= 5; filas++) {
            for (columnas = 0; columnas <= 2; columnas++) {
                grid[elemento] = Sudoku[filas][columnas];
                elemento++;
                if (elemento == 10) {
                    break;
                }

            }
        }

        grid_valido = 1;

        for (comparador = 0; comparador < 9; comparador++) {
            primer_elemento = grid[comparador];

            for (elemento = comparador; elemento < 9; elemento++) {
                segundo_elemento = grid[elemento + 1];
                if (primer_elemento == segundo_elemento) {
                    grid_valido = 0;
                }

            }
        }
        if (grid_valido == 1) {
            contador_grids_validos = contador_grids_validos + 1;
        }

        // GRID 5

        elemento = 0;
        for (filas = 3; filas <= 5; filas++) {
            for (columnas = 3; columnas <= 5; columnas++) {
                grid[elemento] = Sudoku[filas][columnas];
                elemento++;
                if (elemento == 10) {
                    break;
                }

            }
        }

        grid_valido = 1;

        for (comparador = 0; comparador < 9; comparador++) {
            primer_elemento = grid[comparador];

            for (elemento = comparador; elemento < 9; elemento++) {
                segundo_elemento = grid[elemento + 1];
                if (primer_elemento == segundo_elemento) {
                    grid_valido = 0;
                }

            }
        }
        if (grid_valido == 1) {
            contador_grids_validos = contador_grids_validos + 1;
        }

        // GRID 6

        elemento = 0;
        for (filas = 3; filas <= 5; filas++) {
            for (columnas = 6; columnas <= 8; columnas++) {
                grid[elemento] = Sudoku[filas][columnas];
                elemento++;
                if (elemento == 10) {
                    break;
                }

            }
        }

        grid_valido = 1;

        for (comparador = 0; comparador < 9; comparador++) {
            primer_elemento = grid[comparador];

            for (elemento = comparador; elemento < 9; elemento++) {
                segundo_elemento = grid[elemento + 1];
                if (primer_elemento == segundo_elemento) {
                    grid_valido = 0;
                }

            }
        }
        if (grid_valido == 1) {
            contador_grids_validos = contador_grids_validos + 1;
        }

        // GRID 7

        elemento = 0;
        for (filas = 6; filas <= 8; filas++) {
            for (columnas = 0; columnas <= 2; columnas++) {
                grid[elemento] = Sudoku[filas][columnas];
                elemento++;
                if (elemento == 10) {
                    break;
                }

            }
        }

        grid_valido = 1;

        for (comparador = 0; comparador < 9; comparador++) {
            primer_elemento = grid[comparador];

            for (elemento = comparador; elemento < 9; elemento++) {
                segundo_elemento = grid[elemento + 1];
                if (primer_elemento == segundo_elemento) {
                    grid_valido = 0;
                }

            }
        }
        if (grid_valido == 1) {
            contador_grids_validos = contador_grids_validos + 1;
        }

        // GRID 8

        elemento = 0;
        for (filas = 6; filas <= 8; filas++) {
            for (columnas = 3; columnas <= 5; columnas++) {
                grid[elemento] = Sudoku[filas][columnas];
                elemento++;
                if (elemento == 10) {
                    break;
                }

            }
        }

        grid_valido = 1;

        for (comparador = 0; comparador < 9; comparador++) {
            primer_elemento = grid[comparador];

            for (elemento = comparador; elemento < 9; elemento++) {
                segundo_elemento = grid[elemento + 1];
                if (primer_elemento == segundo_elemento) {
                    grid_valido = 0;
                }

            }
        }
        if (grid_valido == 1) {
            contador_grids_validos = contador_grids_validos + 1;
        }

        // GRID 9

        elemento = 0;
        for (filas = 6; filas <= 8; filas++) {
            for (columnas = 6; columnas <= 8; columnas++) {
                grid[elemento] = Sudoku[filas][columnas];
                elemento++;
                if (elemento == 10) {
                    break;
                }

            }
        }

        grid_valido = 1;

        for (comparador = 0; comparador < 9; comparador++) {
            primer_elemento = grid[comparador];

            for (elemento = comparador; elemento < 9; elemento++) {
                segundo_elemento = grid[elemento + 1];
                if (primer_elemento == segundo_elemento) {
                    grid_valido = 0;
                }

            }
        }
        if (grid_valido == 1) {
            contador_grids_validos = contador_grids_validos + 1;
        }

        System.out.println("Hay " + contador_grids_validos + " grids válidos en este sudoku");

        return contador_grids_validos;
    }

}
// final
