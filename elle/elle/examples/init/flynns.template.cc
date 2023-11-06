#include <stdio.h>
#include <math.h>
#include "attrib.h"
#include "nodes.h"
#include "update.h"
#include "error.h"
#include "runopts.h"
#include "file.h"
#include "interface.h"
#include "init.h"

int DoSomethingToFlynn(int flynn);
int InitThisProcess(), ProcessFunction();

/*
 * this function will be run when the application starts,
 * when an elle file is opened or
 * if the user chooses the "Rerun" option
 */
int InitThisProcess()
{
    char *infile;
    int err=0;
    
    /*
     * clear the data structures
     */
    ElleReinit();

    ElleSetRunFunction(ProcessFunction);

    /*
     * read the data
     */
    infile = ElleFile();
    if (strlen(infile)>0) {
        if (err=ElleReadData(infile)) OnError(infile,err);
        /*
         * check for any necessary attributes which may
         * not have been in the elle file
         */
        if (!ElleFlynnAttributeActive(ValidAtt))
            ElleAttributeNotInFile(infile,ValidAtt);
    }
}

int ProcessFunction()
{
    int i, k, l;
    int err=0,max;
    
    ElleCheckFiles();

    for (i=0;i<EllemaxStages();i++) {
        max = ElleMaxFlynns();
        for (k=0;k<max;k++) {
            if (ElleFlynnIsActive(k)) {
                err = DoSomethingToFlynn(k);
                .
                .
            }
        }
        /*
         * update the count and redisplay
         * check whether to write an elle file
         */
        ElleUpdate();
    }
    return(err);
} 
             
int DoSomethingToFlynn(int flynn)
{
    .
    .
    .
}