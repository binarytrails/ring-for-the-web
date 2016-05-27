#!/usr/bin/node

var ipPortRegex = require('ip-port-regex'),
    program = require('commander'),
    express = require('express'),
    app = express(),
    server = require('http').Server(app),
    io = require('socket.io')(server),
    _ = require('underscore'),
    path = require('path'),
    childProcess = require('child_process'),
    // Ring-daemon C++ interface
    wring = require('./build/Release/wring');

function init()
{
    program
      .version('1.0.0')
      .usage('[options] <file ...>')
      .option('-a, --address <ip:port>', 'listen on the ip address and port', ipPortRegex.v4())
      .option('-v, --verbose', 'A value that can be increased')
      .parse(process.argv);

    if (!program.address)
    {
        program.address = "127.0.0.1:8000";
    }
}

function startDaemon()
{
    if(program.verbose)
    {
        console.log('Starting the daemon')
    }

    childProcess.exec('dring', function(error, stdout, stderr)
    {
        if(program.verbose)
        {
            console.log(stdout);
        }
        console.log(stderr);
        if(error)
        {
            console.log(error);
        }
    });
}

function startServer()
{
    if(program.verbose)
    {
        console.log('Starting the server');
    }

    server.listen(ipPortRegex.parts(program.address)['port'],
            ipPortRegex.parts(program.address)['ip'], function()
            {
                console.log('Listening on http://%s:%s',
                        server.address().address,
                        server.address().port
                );
            }
    );

    app.use(express.static(__dirname + '/public'));

    app.get('/', function(req, res)
    {
        res.sendFile(__dirname + '/index.html');
    });

    io.on('connection', function(socket)
    {
        socket.emit('setContent', 'Pushed: ' + wring.hello());

        socket.on('getContent', function()
        {
            socket.emit('setContent', 'Pulled: ' + wring.hello());
        });
    });
}

init()
startDaemon();
startServer();

