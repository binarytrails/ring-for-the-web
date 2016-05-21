from flask import Flask
from flask_restful import Resource, Api

class Router(Resource):
    def get(self):
        return {'hello': 'world'}

class Server:
    def __init__(self):
        self.app = Flask(__name__)
        self.api = Api(self.app)

        self.api.add_resource(Router, '/')
        self.app.run(debug=True)

if __name__ == '__main__':
    Server()

