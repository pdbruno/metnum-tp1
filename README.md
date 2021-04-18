# metnum-tp1

Primero nos pararemos dentro de la carpeta src para facilitar el uso de las herramientas.

```
cd src
```

## Compilar

```
python metnum.py build
```

## Ejecutar

```
./tp [in] [out] [metodo]
```

- `metodo`

| # | Método |
| - | - |
| 0 | CMM |
| 1 | WP |
| 3 | Keener |
| 4 | CMM utilizando Cholesky |
| 5 | Comparacion de rankings de CMM vs WP vs Keener |

- `in` path al archivo de entrada
- `out` path al archivo de salida

Ejemplo

```
./tp ../data/nba_2016_scores.dat outs/output 2
```

## Experimentacion

Para ejecutar la experimentacion realizada por el grupo, podemos utilizar el metodo 5 del ejecutable para 
comparar los rankings generados por los 3 metodos implementados.

### Formato output

Este modo 5 escribira en el archivo de salida indicado algo de la siguiente forma:

CON CMM  
equipo: -, rating: -  
...  
CON WP  
equipo: -, rating: -  
...  
CON KEENER  
equipo: -, rating: -  
...  

De esta forma podemos facilmente comparar el ranking generado por cada metodo viendo en que posicion quedo cada equipo.

#### Listado de experimentos

Cada uno de los siguientes expirmentos esta explicado en el informe.

| Nombre | Archivo input
| - | - |
| Equipo 1 es ganador pero con pocos goles | equipoGanador_pocosGoles.in |
| Equipo jug ́o un partido y lo gan ́o | equipo_gano_uno_jugo_uno.in |
| Ganador Optimizado para CMM | ganadorOptimizado.in |
| Goles distribuidos vs acumulados | golesDistribuidosVsAcumulados.in |
| Iguales ganados, distintos perdidos, goles distintos | igualGanados_distintosPerdidos_golesDistintos.in |
| Iguales ganados, iguales perdidos, goles distintos | igualGanados_distintosPerdidos_golesDistintos.in |  

### Cuantitativo

Resultado del analisis cuantitativo con los resultados de la catedra.

```
python metnum.py error_compare
```
Este script va a calcular el error promedio entre el contenido de los archivos expected y el resultado del metodo en C++.
Este metodo sera cual sea seteado manualmente en el archivo de `scripts/settings`

- Resultado: el error sera mostrado por consola

### Tests

Los tests se pueden ejecutar para todo modo menos el 5.

```
python metnum.py test
```

Donde se utilizara el metodo seteado en `scripts/settings`.
Los expected utilizados para WP y Keener fueron generados con:

```
cd python_impl/
python expected_generator.py
```