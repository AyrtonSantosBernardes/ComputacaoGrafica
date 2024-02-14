# Atividade 06 - Metal e Vidro

Este é um programa em C++ que realiza a renderização de imagens utilizando a técnica de Ray Tracing. O programa cria uma cena tridimensional composta por esferas, triângulos e objetos 3D a partir de arquivos no formato OBJ. Ele define diferentes materiais para os objetos da cena e configurações de câmera para capturar a cena sob ângulos diferentes, gerando imagens da cena renderizada.

## Pré-requisitos:

- Biblioteca "stb_image_write.h" - Download: https://github.com/nothings/stb/blob/master/stb_image_write.h

- Visual Studio Code com as extensões: C/C++,  C/C++ Compile Run

## Compilação e Execução

Para compilar o programa, você precisa ter um compilador C++ instalado em seu sistema. Certifique-se de que os arquivos necessários estejam presentes no diretório de compilação. Em seguida, execute o comando de compilação apropriado para o seu ambiente.

Por exemplo, se estiver usando g++, você pode compilar o programa com o seguinte comando:

```bash
g++ main.cpp -o main.exe
```

Após a compilação bem-sucedida, você pode executar o programa digitando:

```bash
.\Main.exe
```

## Funcionamento

O programa cria uma cena composta por esferas e objetos 3D carregados de arquivos OBJ. Além disso, define diferentes materiais para os objetos da cena, incluindo chão preto, cubo de platina, cubo azul fosco e esfera de vidro. Em seguida, configura uma câmera para capturar a cena sob um ângulo específico. A câmera gera uma imagem da cena renderizada com base em suas configurações.

## Arquivos

- `main.cpp`: Contém a função principal (`main`) que coordena a renderização das imagens.
- `scr/rtweekend.h`: Arquivo de cabeçalho contendo funções utilitárias e constantes.
- `scr/hittable.h`, `scr/hittable.cpp`: Define a interface `hittable` e implementa uma lista de objetos que podem ser atingidos por raios.
- `scr/sphere.h`, `scr/sphere.cpp`: Define a classe `sphere` para representar esferas na cena.
- `scr/triangle.h`, `scr/triangle.cpp`: Define a classe `triangle` para representar triângulos na cena.
- `scr/object.h`, `scr/object.cpp`: Define a classe `object` para representar objetos 3D carregados de arquivos OBJ.
- `scr/export_image.cpp`: Contém funções para exportar imagens em formato PNG.
- `scr/color.h`, `scr/color.cpp`: Define a classe `color` para representação de cores.
- `scr/camera.h`, `scr/camera.cpp`: Define a classe `camera` para representação e renderização de câmeras.
