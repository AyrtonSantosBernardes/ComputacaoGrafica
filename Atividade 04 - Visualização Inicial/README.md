# Atividade 04 - Visualização Inicial

Este é um programa em C++ que implementa um simples traçador de raios para renderização de imagens. Ele pode renderizar esferas, triângulos e objetos 3D a partir de arquivos no formato OBJ. O programa gera imagens em formato PNG para círculos, triângulos e objetos 3D.

## Pré-requisitos:

- Biblioteca "stb_image_write.h" - Download: https://github.com/nothings/stb/blob/master/stb_image_write.h

- Visual Studio Code com as extensões: C/C++,  C/C++ Compile Run

## Compilação e Execução

Certifique-se de ter um compilador C++ instalado em seu sistema. Este programa foi testado usando o compilador g++.

Para compilar o programa, você pode executar o seguinte comando no terminal:

```bash
g++ main.cpp -o main.exe
```

Após a compilação bem-sucedida, você pode executar o programa digitando:

```bash
.\Main.exe
```

## Funcionamento

O programa gera imagens de círculos, triângulos e objetos 3D.

Para círculos, ele verifica se um raio atinge a esfera especificada e, se sim, pinta o pixel com uma cor vermelha.

Para triângulos, verifica se um raio atinge o triângulo especificado e pinta o pixel com uma cor vermelha se atingir.

Para objetos 3D, ele lê um arquivo no formato OBJ, calcula a interseção dos raios com os triângulos do objeto e pinta o pixel com uma cor vermelha se atingir um triângulo.

## Arquivos
- `main.cpp`: Contém a função principal (`main`) que coordena a renderização das imagens.
- `src/Image.cpp`: Implementa a classe `Image` para geração de imagens em formato PNG.
- `src/vec3.cpp`: Implementa a classe `vec3` para manipulação de vetores 3D.
- `src/object_reader.cpp`: Implementa a classe `ObjectReader` para leitura de arquivos no formato OBJ.
- `src/color.cpp`: Implementa a classe `color` para representação de cores.
- `src/ray.cpp`: Implementa a classe `ray` para representação de raios.
