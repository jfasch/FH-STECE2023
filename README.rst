Development Docs
================

.. contents::
   :local:

.. sidebar::

   * Github project: https://github.com/jfasch/FH-STECE2023
   * Github workflow (forks, and pull requests):
     :doc:`jfasch:about/site/work-in-progress/fh-joanneum/2021/git/git`

Getting The Source
------------------

.. code-block:: console

   $ cd ~/My-Projects                       # <--- or wherever you like
   $ git clone https://github.com/jfasch/FH-STECE2023.git
   $ ls -l FH-STECE2023/
   ...
   -rw-r--r--. 1 jfasch jfasch  733 Apr  9 16:07 blink.cpp
   -rw-r--r--. 1 jfasch jfasch  318 Apr  9 16:07 CMakeLists.txt
   -rw-r--r--. 1 jfasch jfasch 4964 Apr  9 16:17 README.rst

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
