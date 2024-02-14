# Animação com Implementações de Ray Tracing

O código apresentado neste repositório corresponde à implementação de uma animação utilizando técnicas de ray tracing. O objetivo do projeto é desenvolver uma animação de pelo menos 5 segundos, composta por diferentes objetos e movimentos de câmera.

## Grupo
O desenvolvimento deste projeto foi realizado em grupo, composto por:

- Ayrton Santos Bernardes RA:792169
- Karen Heimer Correa RA: 771028
- Letícia Almeida Paulino de Alencar Ferreira RA: 800480

## Descrição
O código principal (`main.cpp`) define a cena da animação, composta por objetos como esferas e cubos. Cada objeto possui um material, podendo ser difuso, reflexivo ou transparente. Além disso, são aplicados movimentos de câmera e rotações nos objetos para gerar uma animação dinâmica.

## Requisitos
- C++ Compiler
- Bibliotecas necessárias: `iostream`, `sstream`, `string`, `fstream`, `chrono`
- Implementações de Ray Tracing (`rtweekend.h`, `hittable.h`, `hittable_list.h`, `sphere.h`, `triangle.h`, `object.h`, `export_image.cpp`, `color.h`, `camera.h`, `animation.h`)
- Biblioteca "stb_image_write.h" - Download: https://github.com/nothings/stb/blob/master/stb_image_write.h

## Compilação e Execução

Para compilar o programa, você precisa ter um compilador C++ instalado em seu sistema. Certifique-se de que os arquivos necessários estejam presentes no diretório de compilação. Em seguida, execute o comando de compilação apropriado para o seu ambiente.

Por exemplo, se estiver usando g++, você pode compilar o programa com o seguinte comando:

```bash
g++ main.cpp -o main.exe
```
## Configurações da Animação

- Duração: 5 segundos
- Resolução: 800x600
- Quadros por segundo: 15

## Componentes da Cena
- Chão Preto
- Esfera de Vidro
- Cubo de Platina
- Segundo Cubo Azul Fosco

## Movimentos
- Movimento de câmera ao redor da cena
- Rotação do cubo de platina sobre o próprio eixo

## Resultado Final

https://github.com/AyrtonSantosBernardes/ComputacaoGrafica/assets/64613710/9f7e4c3a-11db-458b-a983-0b96bb64fea7
