# TC3041-P4-Primavera-2019


# Problema

Una fábrica tiene la necesidad de recopilar información,en tiempo real, sobre sus máquinas y poder visualizarla en un sistema centralizado para tener un monitoreo más eficiente sobre su estado.

# Descripción

## Mediciones

- Temperatura de la máquina
- Presión del aire dentro de la máquina
- Energia usada por la maquina

## Tags

- Máquina = (nombre de la máquina)

## Valores

- Temperatura -> grados = (50-250 ºC)
- Presión del aire -> kPa = (100-1000 kPa)
- Energía -> kw = (100 - 1000 kw)

## Generar datos
1. c++ InfluxDataGenerator.cpp -o InfluxDataGenerator -> compilar código
2. ./InfluxDataGenerator -> ejecutar

## Importar datos a Influxdb (comandos)

1. docker run --name influxdb -d -p 8086:8086 -v $PWD:/var/lib/influxdb influxdb
2. docker run -d -p 3000:3000 --name=grafana -e "GF_SERVER_ROOT_URL=http://grafana.server.name" -e "GF_SECURITY_ADMIN_PASSWORD=secret" grafana/grafan
3. docker cp data.txt influxdb:
4. docker exec -it influxdb bash
5. influx -import -path=data.txt -precision=s
