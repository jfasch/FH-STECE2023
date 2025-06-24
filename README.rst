Development Docs
================

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
