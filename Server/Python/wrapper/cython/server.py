from dring import Dring

from bottle import run
from api import help, user

def startServer():
    run(host='localhost', port=8080)

if __name__ == "__main__":
    Dring()
    startServer()
