# pushswap-v2

#### To run

    install coreutils
    ARG=$(echo $(seq 10 | shuf));./ps $ARG
	ARG=`ruby -e "puts (1..50).to_a.shuffle.join(' ')"``; ./push_swap $ARG