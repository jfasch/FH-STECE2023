Development Docs
================

.. contents::
   :local:

.. sidebar::

   * Github project: https://github.com/jfasch/FH-STECE2023
   * Github workflow (forks, and pull requests):
     :doc:`jfasch:about/site/work-in-progress/fh-joanneum/2021/git/git`

Getting The Source, Setup
-------------------------

.. code-block:: console

   $ cd ~/My-Projects                       # <--- or wherever you like
   $ git clone https://github.com/jfasch/FH-STECE2023.git
   $ cd FH-STECE2023
   $ git submodule init
   $ git submodule update

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

Build
-----

Create build directory for Intel architecture (``x86_64``)

.. code-block:: console

   $ mkdir ~/My-Builds/FH-STECE2022-x86_64  # <--- or wherever you like
   $ cd ~/My-Builds/FH-STECE2022-x86_64
   $ cmake ~/My-Projects/FH-STECE2022
   ... roedel ...
   $ make
   ... roedel ...

Test
----

In build directory,

.. code-block:: console

   $ pwd
   /home/jfasch/My-Builds/FH-STECE2022-x86_64

   $ ./blink
   ... ?
