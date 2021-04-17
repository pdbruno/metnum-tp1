import pandas as pd
import numpy as np
import sys


#../outs/equipo_gano_uno_jugo_uno.out

io = open(sys.argv[1], "r")
rankings = {

}

def leer_metodo_utilizado(fila):
    if fila[4] == "C":
        return "CMM"
    elif fila[4] == "W":
        return "WP"
    elif fila[4] == "K":
        return "Keener"
def tomar_equipo(fila):
    numero = ""
    i = 8
    while(fila[i]!=","):
        numero = numero + fila[i]
        i = i + 1
    
    return int(numero)

def tomar_puntaje(fila):
    puntaje = ""
    i = 19
    while(fila[i:] != '\n' ):
        puntaje = puntaje + fila[i]
        i =i + 1
    return float(puntaje)


def read_out(io, n_call, fila):
    # escribe en el diccionario rankings todos los rankings generados, 
    # luego sera pasado a DF donde cada metodo tendra su columna
    print("comienza read")
    if((fila != '') and (fila[0]=="C")):
    
        equipos = []
        puntajes = []
        metodo = leer_metodo_utilizado(fila)
        fila = io.readline()
        while((fila != '') and (fila[0] == "e")):
            print("comienza while")
            equipos.append(tomar_equipo(fila))
            puntajes.append(tomar_puntaje(fila))
            fila = io.readline()
        

        ranking = pd.Series(puntajes, index=equipos)
        rankings[metodo] = ranking
        print(ranking)
        # hacemos otra llamada para tomar los otros metodos
        n_call = n_call + 1
        
        if(fila != ''):
            read_out(io, n_call,fila)


read_out(io,0,io.readline())
res = pd.DataFrame(rankings)
print(res)



print(rankings)

res.to_csv(sys.argv[1][8:]+"_df.csv")