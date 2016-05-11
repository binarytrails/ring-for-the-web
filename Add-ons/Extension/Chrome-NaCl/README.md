# Chrome-extension

First things first, you'll have to install the Nacl SDK

## Native Client SDK

1. Download the [SDK](https://storage.googleapis.com/nativeclient-mirror/nacl/nacl_sdk/nacl_sdk.zip).
2. Unzip it and go in the extracted directory.
3. If you're using ```python``` as an alias for ```python2.7```, go to the next step. Else, you'll have to setup a virtual environment of python2.7 with [virtualenv](https://virtualenv.pypa.io/en/latest/).
4. Run ```./naclsdk install ``` to install the latest [Pepper API](https://developer.chrome.com/native-client/pepper_stable) stable bundle
5. Then, got to the newest pepper bundle with ```cd pepper_XX``` (XX is the version's number)
6. And export the path to the sdk to your shell profile file with ```echo export NACL_SDK=`pwd` >> ~/.bashrc```
7. Reload it with ```source ~/.bashrc```

## Build the extension
A simple ```make``` will do the trick. Be sure that the virtual environment is still activated. The SDK still needs python2.7

## Install the extension

1. Go to *chrome://extensions/*
2. Click on *Developer Mode*
3. Click on *Load unpacked extension*
5. Select the project folder directory

More info on the [Google's native client page](https://developer.chrome.com/native-client)
