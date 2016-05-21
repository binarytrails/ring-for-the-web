import bottle
from bottle import route, run, request

@route('/hello', method='GET')
def hello():
    return 'world!'

def startServer():
    run(host='localhost', port=8080)

#startServer()
