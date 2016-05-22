from bottle import request, get

@get('/user/')
def hello():
    return 'Yes you are! Ask an action to <i>/user/userId/action/</i>'

@get('/user/<userId>/<action>/')
def user(userId, action):
    response = "Performing " + action + " for " + userId + "."
    return response

