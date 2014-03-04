SixenseJava
============

	A Java wrapper for the Sixense dynamic libraries.
    
    This wrapper has been tested and confirmed to work with the latest
    libraries as of 3/3/2014.
    
    Place dynamic libraries in the projact/program's root folder by default for
    SixenseJava to load the required libraries. An example for Windows:
    |-SixenseGame
      |-Game.jar
      |-SixenseJava.jar
      |-SixenseJava32.dll
      |-SixenseJava64.dll
      |-sixense.dll
      |-sixense_utils.dll
      |-sixense_x64.dll
      |-sixense_utils_x64.dll
    
    The libraries can also be placed in the Path if that works better or
    can be specify the java.library.path java system property by the
    -Djava.library.path= command line arguement or with
    System.setProperty(java.library.path) at runtime.

License
============

   Copyright © 2013 SixenseJava Contributors

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.