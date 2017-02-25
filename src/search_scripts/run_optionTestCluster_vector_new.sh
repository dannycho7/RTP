#!/bin/bash

# $1 -> query, $2 -> query length
pwd
top_k=1

if [ -z "$1" ]; then
    echo "The query cannot be empty."
else
#echo ""
#echo "************************************************"
#echo "Run query: $1"
    # Step 1: In phase1_rep: run lucene package to generate "search_frag.txt"
    cd ./target/
    #edit query
    rm -rf search_frag.txt
    java -jar ../src/phase1/search_doc/lucene_search.jar $1 #&> /dev/null


    # Step 2: In phase1: run search_doc to generate "vidlist.txt" & "result.txt"
    ./phase1_search_doc $2 $1 #&> /dev/null


    # Step 3: In phase2: run "runjob_optionC.py" for optionC and "runjob_optionA.py" for optionA
    # edit query
    #sed -i "s/query_len = .*#!!!/query_len = $2#!!!/g" runjob_optionTestCluster_vector_new.py
    #sed -i "s/k=.*#!!!/k=$top_k#!!!/g" runjob_optionTestCluster_vector_new.py
    #sed -i '' "s/.\/index_search --index index --no-features --postings <<< '.*/.\/index_search --index index --no-features --postings <<< '$1'/g" lucene_step/run_search_qinghao.sh
    #sed -i "s/query_len = .*#!!!/query_len = $2#!!!/g" calculateTestCluster.py
    #sed -i "s/k = .*#!!!/k = $top_k#!!!/g" calculateTestCluster.py

#echo
#echo ">>>> Start Searching using OptionTestCluster <<<<"
#echo
    python ../src/phase2/runjob_optionTestCluster_vector_new.py "$1" $2 $top_k #&> /dev/null
#echo ">>>> Finish Searching using OptionTestCluster <<<<"

fi
