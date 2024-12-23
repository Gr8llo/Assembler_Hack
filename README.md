# Hack Assembler / Assemblatore Hack

## Descrizione / Description

Questo progetto implementa un **assemblatore** per il **computer Hack**, sviluppato come parte di **nand2tetris**. L'assemblatore è scritto in **C** e può essere avviato tramite un **Makefile**. Il programma converte file di codice assembly Hack (con estensione '`.asm`) in file binari eseguibili (con estensione `.hack`).

This project implements an **assembler** for the **Hack computer**, developed as part of the **nand2tetris** project. The assembler is written in **C** and can be run through a **Makefile**. The program converts Hack assembly code files (with `.asm` extension) into executable binary files (with `.hack` extension).

## Requisiti / Requirements

### Italiano 

- Un **compilatore C** (ad esempio GCC).

- **Make** (per la gestione del Makefile)

### English 

- A **C compiler** (e.g., GCC).

- **Make** (for managing the Makefile).

## Installazione / Installation

### Italiano 

1. Clona il repository:
   ```bash
   git clone https://github.com/Gr8llo/Assembler_Hack.git
   ```

2. Accedi alla cartella del progetto:
   ```bash
   cd Assembler_Hack
   ```

3. Compila il progetto usando il comando `make`:
   ```bash
   make main
   ```

4. Esegui il programma assemblatore passando un file `.asm` come argomento:
   ```bash
   ./main nome_file.asm
   ```

   Questo genererà un file `nome_file.hack` contenente il codice binario.


### English

1. Clone the repository:
   ```bash
   git clone https://github.com/Gr8llo/Assembler_Hack.git
   ```

2. Navigate to the project folder:
   ```bash
   cd Assembler_Hack
   ```

3. Compile the project using the `make` command:
   ```bash
   make main
   ```

4. Run the assembler program by passing an `.asm` file as an argument:
   ```bash
   ./main file_name.asm
   ```

   This will generate a `file_name.hack` file containing the binary code.

## Pulizia / Cleaning

### Italiano 

Per rimuovere i file oggetto e i file binari generati, esegui:

```bash
make clean
```

### Inglese 

To remove object files and generated binary files, run:

```bash
make clean
```

## Struttura del Progetto / Project Structure

### Italiano 

- `main.c`: Il file principale contenente la logica dell'assemblatore.
- `libraries/setup.c` e `libraries/setup.h`: Gestione dell'inizializzazione del programma.
- `libraries/assembler.c` e `libraries/assembler.h`: Funzioni per l'elaborazione del codice assembly Hack.
- `libraries/symbol.c` e `libraries/symbol.h`: Gestione delle variabili simboliche (etichette e variabili).
- `Makefile`: Il Makefile per la compilazione del progetto.
- `README.md`: Questo file di documentazione.

### Inglese 

- `main.c`: The main file containing the logic of the assembler.
- `libraries/setup.c` and `libraries/setup.h`: Handling the program's initialization.
- `libraries/assembler.c` and `libraries/assembler.h`: Functions for processing Hack assembly code.
- `libraries/symbol.c` and `libraries/symbol.h`: Managing symbolic variables (labels and variables).
- `Makefile`: The Makefile for compiling the project.
- `README.md`: This documentation file.
