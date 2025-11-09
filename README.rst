Developer Documentation
=======================

.. contents::
   :local:

.. sidebar::

   * Github project: https://github.com/jfasch/FH-STECE2023
   * Github workflow (forks, and pull requests):
     :doc:`jfasch:about/site/work-in-progress/fh-joanneum/2021/git/git`

Optional: Install ``libgpiod``
------------------------------

``libgpiod`` is used to control GPIO pins. It can be left uninstalled
for development purposes - if you develop code that can mock-away
GPIOs then you can omit this step. If you choose to not install it,
then you will have to live with a number of warnings in our project
though.

``libgpiod`` installation has to be done manually, from
source. *Reason*: ``libgpiod`` has had some major version jumps lately
(version 2 is current), and distributions are not yet fully up to
date.

Install ``libgpiod`` Build Prerequisites
........................................

Install a number of development tools that ``libgpiod`` uses.

.. code-block:: console

   $ sudo apt install -y automake autoconf autoconf-archive libtool

Get/Build/Install ``libgpiod``
..............................

Get the source from ``libgpiod``'s upstream repo

.. code-block:: console

   $ git clone https://git.kernel.org/pub/scm/libs/libgpiod/libgpiod.git

Massage the source (in analogy to what we do with CMake)

.. code-block:: console

   $ cd libgpiod/
   $ ./autogen.sh --enable-tools
   $ ./configure --enable-tools --enable-bindings-cxx

Finally, build and install. The installation goes into the default
location ``/usr/local``, where CMake will be able to pick it up in our
project build.

.. code-block:: console

   $ make
   $ sudo make install

Get The Source, Massage The Source
----------------------------------

Clone Project Tree
..................

.. code-block:: console

   $ cd ~/My-Projects                       # <--- or wherever you like
   $ git clone https://github.com/jfasch/FH-STECE2023.git
   $ cd FH-STECE2023

.. code-block:: console

   $ ls -l
   ...
   drwxr-xr-x. 1 jfasch jfasch  158 May  6 12:15 .
   drwxr-xr-x. 1 jfasch jfasch 1558 Apr 25 14:46 ..
   -rw-r--r--. 1 jfasch jfasch  372 May  5 01:33 CMakeLists.txt
   drwxr-xr-x. 1 jfasch jfasch  828 May  6 11:16 exercises
   drwxr-xr-x. 1 jfasch jfasch  272 May  6 12:15 .git
   -rw-r--r--. 1 jfasch jfasch    3 May  5 00:46 .gitignore
   -rw-r--r--. 1 jfasch jfasch   88 May  5 01:32 .gitmodules
   drwxr-xr-x. 1 jfasch jfasch  408 May  5 01:32 googletest
   drwxr-xr-x. 1 jfasch jfasch   46 May  5 00:47 livehacking
   -rw-r--r--. 1 jfasch jfasch 1121 May  6 12:15 README.rst

Pull In ``googletest`` Submodule
................................

.. code-block:: console

   $ git submodule init
   $ git submodule update

Build
-----

Create build directory for Intel architecture (``x86_64``). **Please
do not make that directory a subdirectory of**
``~/My-Projects/FH-STECE2023/`` **!!**

.. code-block:: console

   $ mkdir ~/My-Builds/FH-STECE2023-x86_64             # <-- not in source directory!!
   $ cd ~/My-Builds/FH-STECE2023-x86_64
   $ cmake ~/My-Projects/FH-STECE2023
   ... roedel ...
   $ make
   ... roedel ...

Run Unit Tests
--------------

.. code-block:: console

   $ cd ~/My-Builds/FH-STECE2023-x86_64
   $ ./tests/door-tests 
   Running main() from /home/jfasch/My-Projects/FH-STECE2023/googletest/googletest/src/gtest_main.cc
   [==========] Running 19 tests from 3 test suites.
   [----------] Global test environment set-up.
   [----------] 1 test from door_suite
   [ RUN      ] door_suite.straightforward_open
   [       OK ] door_suite.straightforward_open (0 ms)
   [----------] 1 test from door_suite (0 ms total)
   
   [----------] 15 tests from timespec_suite
   [ RUN      ] timespec_suite.default_ctor
   [       OK ] timespec_suite.default_ctor (0 ms)
   [ RUN      ] timespec_suite.ctor_from_good_old
   [       OK ] timespec_suite.ctor_from_good_old (0 ms)
   [ RUN      ] timespec_suite.explicit_ctor
   [       OK ] timespec_suite.explicit_ctor (0 ms)
   [ RUN      ] timespec_suite.copy_from_good_old
   [       OK ] timespec_suite.copy_from_good_old (0 ms)
   [ RUN      ] timespec_suite.copy_ctor
   [       OK ] timespec_suite.copy_ctor (0 ms)
   [ RUN      ] timespec_suite.assignment_operator
   [       OK ] timespec_suite.assignment_operator (0 ms)
   [ RUN      ] timespec_suite.less
   [       OK ] timespec_suite.less (0 ms)
   [ RUN      ] timespec_suite.equals_and_notequals
   [       OK ] timespec_suite.equals_and_notequals (0 ms)
   [ RUN      ] timespec_suite.greater
   [       OK ] timespec_suite.greater (0 ms)
   [ RUN      ] timespec_suite.less_equal
   [       OK ] timespec_suite.less_equal (0 ms)
   [ RUN      ] timespec_suite.greater_equal
   [       OK ] timespec_suite.greater_equal (0 ms)
   [ RUN      ] timespec_suite.now_monotonic
   [       OK ] timespec_suite.now_monotonic (0 ms)
   [ RUN      ] timespec_suite.from_milliseconds
   [       OK ] timespec_suite.from_milliseconds (0 ms)
   [ RUN      ] timespec_suite.add
   [       OK ] timespec_suite.add (0 ms)
   [ RUN      ] timespec_suite.sub
   [       OK ] timespec_suite.sub (0 ms)
   [----------] 15 tests from timespec_suite (0 ms total)
   
   [----------] 3 tests from eventedge_suite
   [ RUN      ] eventedge_suite.rising_edge
   [       OK ] eventedge_suite.rising_edge (0 ms)
   [ RUN      ] eventedge_suite.falling_edge
   [       OK ] eventedge_suite.falling_edge (0 ms)
   [ RUN      ] eventedge_suite.none_edge
   [       OK ] eventedge_suite.none_edge (0 ms)
   [----------] 3 tests from eventedge_suite (0 ms total)
   
   [----------] Global test environment tear-down
   [==========] 19 tests from 3 test suites ran. (0 ms total)
   [  PASSED  ] 19 tests.



Refactoring and Architecture
============================

.. contents::
   :local:

Motivation
----------

The `door` module is currently undergoing structural refactoring to improve separation of concerns,
maintainability, and testing flexibility. The goal is to modularize components such as motors,
sensors, and GPIO interfaces into isolated libraries.

Structural Refactoring — Proposal
---------------------------------

This section outlines the proposed plan for the refactoring of the `src/door` module.

Ziel
----

This document describes the proposed structural refactoring plan for the `src/door` module. The goal is a clear separation of responsibilities, improved clarity through directories, and better test/deployment flexibility via separate libraries (Core / Mocks / Hardware).

Inhalt
------

.. contents::
   :local:

1. Kurzüberblick
2. Neue Verzeichnisstruktur
3. Include-Konventionen
4. CMake: Option B (Multi-Library) — vollständiges Beispiel
5. Schritt-für-Schritt-Migrationsanleitung (Git-kompatibel)
6. Tests & Debugging
7. README / .rst Dokumentation (Vorlage)

1. Kurzüberblick
-----------------

Instead of keeping all files flat in `src/door/`, the module will be split into multiple logical subdirectories (e.g., `core`, `common`, `motor`, `input_switch`, `output_switch`, `pressure_sensor`).

Key design decisions:

* Each component contains its interface (header), mock implementations, and — if present — hardware implementations.
* Within a module: local includes with quotes, e.g., ``#include "motorLED.h"``.
* Between modules: system-include syntax with project root `door`, e.g., ``#include <door/motor/motor.h>``.
* CMake generates three libraries: `door_core`, `door_mocks`, and `door_hw`.

2. Neue Verzeichnisstruktur
---------------------------

.. code-block:: text

   src/door/
   ├── CMakeLists.txt
   ├── core/
   │   ├── door.h
   │   └── door.cpp
   ├── common/
   │   ├── structs.h
   │   └── timespec.cpp
   ├── motor/
   │   ├── motor.h
   │   ├── motor-mock.cpp
   │   └── motorLED.cpp
   ├── input_switch/
   │   ├── input-switch.h
   │   └── input-switch-mock.cpp
   ├── output_switch/
   │   └── ...
   └── pressure_sensor/
       └── ...

3. Include-Konventionen
-----------------------

* Within the same module (e.g., `motor`):

.. code-block:: cpp

   #include "motorLED.h"   // local header file

* Between modules (always from project include root):

.. code-block:: cpp

   #include <door/motor/motor.h>
   #include <door/common/structs.h>

This avoids "../"-includes and keeps include paths stable if files are moved or libraries are separated.

4. CMake: Option B (Multi-Library) — vollständiges Beispiel
-----------------------------------------------------------

.. code-block:: cmake

   # --- Project-specific files for door_core, door_mocks, door_hw ---
   # door_core: core logic + interfaces (no hardware)
   set(DOOR_CORE_FILES
     core/door.h
     core/door.cpp
     core/inputs.h
     core/inputs.cpp
     core/outputs.h
     core/outputs.cpp
     common/structs.h
     common/timespec.h
     common/timespec.cpp
     common/event-edge-detector.h
     common/event-edge-detector.cpp
     motor/motor.h
     input_switch/input-switch.h
     output_switch/output-switch.h
     pressure_sensor/pressure-sensor.h
   )

   add_library(door_core ${DOOR_CORE_FILES})
   target_include_directories(door_core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..)

   # door_mocks: mocks implement interfaces from door_core
   set(DOOR_MOCK_FILES
     motor/motor-mock.cpp
     input_switch/input-switch-mock.cpp
     output_switch/output-switch-mock.cpp
     pressure_sensor/pressure-sensor-mock.cpp
   )

   add_library(door_mocks ${DOOR_MOCK_FILES})
   target_include_directories(door_mocks PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..)
   target_link_libraries(door_mocks PUBLIC door_core)

   # door_hw: hardware implementations - only if libs present
   find_package(PkgConfig QUIET)
   find_package(Libgpiod QUIET)

   if (LIBGPIOD_FOUND)
     set(DOOR_HW_FILES
       motor/motorLED.cpp
       input_switch/input-switch-gpio.cpp
       output_switch/output-switch-gpio.cpp
       pressure_sensor/pressure-sensor-bmp280.cpp
     )
     add_library(door_hw ${DOOR_HW_FILES})
     target_include_directories(door_hw PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..)
     target_link_libraries(door_hw PUBLIC door_core LIBGPIOD::LIBGPIOD)
   endif()

5. Schritt-für-Schritt-Migrationsanleitung
------------------------------------------

1. Branch erstellen (Git)

.. code-block:: console

   $ git checkout -b refactor/structural

2. Anlegen der neuen Verzeichnisse lokal

.. code-block:: console

   $ mkdir -p src/door/{core,common,motor,input_switch,output_switch,pressure_sensor}

3. Dateien schrittweise verschieben (in kleinen Commits)

* Recommended: move headers first, adjust includes, commit; then move implementations.

.. code-block:: console

   $ git mv src/door/motor.h src/door/motor/motor.h
   $ git mv src/door/motor-mock.cpp src/door/motor/motor-mock.cpp
   $ git add -A
   $ git commit -m "refactor(motor): move motor files into motor/ and update includes"

4. CMake anpassen

* Replace old DOOR_FILES list with new paths or use multi-library setup above.
* Ensure `target_include_directories(... ${CMAKE_CURRENT_SOURCE_DIR}/..)` remains.

5. Build & Tests

.. code-block:: console

   $ mkdir -p ~/My-Builds/FH-STECE2023-x86_64
   $ cd ~/My-Builds/FH-STECE2023-x86_64
   $ cmake /path/to/FH-STECE2023
   $ make -j$(nproc)
   $ ./tests/door-tests

6. Iteriere: fix compile errors, include paths, linker errors in small commits.

6. Tests & Debugging
--------------------

* Run unit tests after each significant step.
* If linker errors occur: check that target is added and linked in CMake.
* For include errors: check spelling and that `target_include_directories(... ${CMAKE_CURRENT_SOURCE_DIR}/..)` is set.

7. README / .rst Documentation (Vorlage)
----------------------------------------

* Purpose of the new structure
* How to build (short cmake/make instructions)
* How to switch between Mocks and Hardware (which targets to link)
* Example include conventions

Abschluss
---------

This document contains a full template for migrating to the multi-library variant (Option B) and a pragmatic step-by-step Git migration guide. Key points: small steps, frequent build/test, and clear include rules.

