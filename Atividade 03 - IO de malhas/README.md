# Atividade 03 - IO de malhas

## Descrição
Este é um programa em C++ que lida com operações em matrizes 3x3 e vetores 3D. Ele inclui a leitura de arquivos no formato OBJ e exibe informações sobre os vértices, texturas, normais e triângulos presentes no arquivo.

## Pré-requisitos
Certifique-se de ter um compilador C++ instalado em seu sistema. Este programa foi testado com sucesso usando o compilador g++ no ambiente Windows.

## Compilação e Execução
Para compilar o programa, abra o terminal (ou prompt de comando) e navegue até o diretório raiz do projeto. Em seguida, execute o seguinte comando:

```bash
g++ -o main.exe main.cpp src/object_reader.cpp src/vec3.cpp src/mat3.cpp
```

Isso compilará o programa e criará um executável chamado `main.exe` no mesmo diretório.

## Execução do Programa
Para executar o programa, digite o seguinte comando no terminal:

```bash
.\main.exe
```

Isso executará o programa e mostrará as informações dos arquivos OBJ especificados na lista de caminhos.

## Funcionamento
O programa lê arquivos no formato OBJ especificados na lista de caminhos `file_paths`. Para cada arquivo, exibe as seguintes informações:
- Lista de vértices (`v`)
- Lista de texturas (`vt`)
- Lista de normais (`vn`)
- Lista de triângulos (`f`)
Após exibir as informações de um arquivo OBJ, avança para o próximo arquivo na lista.

## Arquivos
- `main.cpp`: Contém a função principal (`main`) que coordena a leitura dos arquivos e a exibição das informações.
- `src/object_reader.cpp`: Implementa a classe `ObjectReader`, responsável pela leitura dos arquivos OBJ.
- `src/vec3.cpp` e `src/mat3.cpp`: Implementam as classes `vec3` e `mat3`, respectivamente, para manipulação de vetores 3D e matrizes 3x3.