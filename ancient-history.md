How We Got Here
===============

In 20 easy steps:

    $ mkdir prjmodel-split
    $ cd prjmodel-split
    $ git init --bare
    $ cd ../OpenStudio
    $ git checkout develop3
    $ git checkout -b splitter e2663cd 
    $ git subtree split --prefix=openstudiocore/src/airflow -b split
    $ git push ../prjmodel-split split:master
    $ cd ..
    $ mkdir prjmodel
    $ cd prjmodel
    $ git init
    $ vi ancient-history.md
    $ git add ancient-history.md
    $ git commit -m "How we got here..."
    $ git remote add -f ancient-history ../prjmodel-split
    $ git merge -s ours --no-commit --allow-unrelated-histories ancient-history/master
    $ git read-tree --prefix='' -u ancient-history/master
    $ git commit -m "Initial code commit"
    $ git remote rm ancient-history
