# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    tester.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-mezz <ael-mezz@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/21 12:18:52 by ael-mezz          #+#    #+#              #
#    Updated: 2021/05/12 15:36:15 by ael-mezz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

red=$'\e[1;31m'
grn=$'\e[1;32m'
yel=$'\e[1;33m'
blu=$'\e[1;34m'
mag=$'\e[1;35m'
cyn=$'\e[1;36m'
end=$'\e[0m'
ERR=0
WRC=0

printf "\e[30;103mTesting checker with non numeric parameters${end}" ############################
RET=`echo rr | ./checker 1 -548368 2478 6p98 .48 ,7`
		if [ "$RET" != "Error!" ];
			then
			printf "\t${red}✘${end}" 
		else
			printf "\t${grn}√${end}" 
        fi
RET=`echo rr | ./checker mate8823 99`
		if [ "$RET" != "Error!" ];
			then
			printf "\t${red}✘${end}\n" 
		else
			printf "\t${grn}√${end}\n" 
        fi

printf "\n\e[30;103mTesting checker with duplicate parameter${end}" ############################
ARG=`ruby -e "puts (-500..500).to_a.shuffle.join(' ')"`
RET=`echo rr | ./checker 250 $ARG`
		if [ "$RET" != "Error!" ];
			then
			printf "\t${red}✘${end}\n" 
		else
			printf "\t${grn}√${end}\n" 
        fi
		
printf "\n\e[30;103mTesting checker with MAXINT parameter${end}\t" ############################
ARG=`ruby -e "puts (-500..500).to_a.shuffle.join(' ')"`
RET=`echo rr | ./checker $ARG 2147483647 -2147483648`
		if [ "$RET" == "Error!" ];
			then
			printf "\t${red}✘${end}" 
		else
			printf "\t${grn}√${end}" 
        fi
ARG=`ruby -e "puts (-500..500).to_a.shuffle.join(' ')"`
RET=`echo rr | ./checker $ARG 2147483648 -2147483649`
		if [ "$RET" != "Error!" ];
			then
			printf "\t${red}✘${end}\n" 
		else
			printf "\t${grn}√${end}\n" 
        fi

printf "\n\e[30;103mTesting checker without any parameter${end}\t" ############################
RET=`echo "" | ./checker  `
		if [ "$RET" != "" ];
			then
			printf "\t${red}✘${end}\n" 
		else
			printf "\t${grn}√${end}\n" 
        fi

printf "\n\e[30;103mTesting checker with unvalid action${end}\t" #############################
ARG=`ruby -e "puts (-500..500).to_a.shuffle.join(' ')"`
RET=`echo rm | ./checker $ARG`
		if [ "$RET" != "Error!" ];
			then
			printf "\t${red}✘${end}" 
		else
			printf "\t${grn}√${end}" 
        fi
RET=`echo rr | ./checker $ARG`
		if [ "$RET" == "Error!" ];
			then
			printf "\t${red}✘${end}" 
		else
			printf "\t${grn}√${end}" 
        fi
RET=`echo "rr   " | ./checker $ARG`
		if [ "$RET" != "Error!" ];
			then
			printf "\t${red}✘${end}" 
		else
			printf "\t${grn}√${end}" 
        fi
RET=`echo "    rr" | ./checker $ARG`
		if [ "$RET" != "Error!" ];
			then
			printf "\t${red}✘${end}\n" 
		else
			printf "\t${grn}√${end}\n" 
        fi

printf "\n\t\e[30;103mTesting with 2 params${end}\n" ##############################
for i in range {1..10}
	do 
		ARG=`ruby -e "puts (-1..0).to_a.shuffle.join(' ')"`
		RET=`./push_swap $ARG | ./checker $ARG`
        ACT=`./push_swap $ARG | wc -l`
		if [ "$RET" != "OK" ];
			then
			((ERR++))
			printf "${red}▓${end}" 
		else
			printf "${grn}▓${end}" 
        fi
        if [ $ACT -gt 12 ];
			then
			((ERR++))
			printf "${red}▓${end}" 
		else
			printf "${grn}▓${end}"
		fi
        if [ $ACT -gt $WRC ];
            then
            WRC=$ACT
        fi
        printf " actions: %-4i" $ACT
        echo ' input: ' $ARG
done
printf "\e[30;103m\tWorst case found: %i ${end}" $WRC

if [ $ERR -eq 0 ];
	then
	printf "${grn}\tSUCCESS [200/200]${end}\n" $ERR
else
	printf "${red}\tFAIL[%i/200] 😱 😱 😱 ${end}\n" $ERR
fi

printf "\n\t\e[30;103mTesting with 3 params${end}\n" ##############################
for i in range {1..20}
	do 
		ARG=`ruby -e "puts (0..2).to_a.shuffle.join(' ')"`
		RET=`./push_swap $ARG | ./checker $ARG`
        ACT=`./push_swap $ARG | wc -l`
		if [ "$RET" != "OK" ];
			then
			((ERR++))
			printf "${red}▓${end}" 
		else
			printf "${grn}▓${end}" 
        fi
        if [ $ACT -gt 12 ];
			then
			((ERR++))
			printf "${red}▓${end}" 
		else
			printf "${grn}▓${end}"
		fi
        if [ $ACT -gt $WRC ];
            then
            WRC=$ACT
        fi
        printf " actions: %-4i" $ACT
        echo ' input: ' $ARG
done
printf "\e[30;103m\tWorst case found: %i ${end}" $WRC

if [ $ERR -eq 0 ];
	then
	printf "${grn}\tSUCCESS [200/200]${end}\n" $ERR
else
	printf "${red}\tFAIL[%i/200] 😱 😱 😱 ${end}\n" $ERR
fi

printf "\n\e[30;103m\tTesting with 5 params${end}\n" ##############################
ERR=0
WRC=0
for i in range {1..99}
	do 
		ARG=`ruby -e "puts (0..4).to_a.shuffle.join(' ')"`
		RET=`./push_swap $ARG | ./checker $ARG`
        ACT=`./push_swap $ARG | wc -l`
		if [ "$RET" != "OK" ];
			then
			((ERR++))
			printf "${red}▓${end}" 
		else
			printf "${grn}▓${end}" 
        fi
        if [ $ACT -gt 12 ];
			then
			((ERR++))
			printf "${red}▓${end}" 
		else
			printf "${grn}▓${end}"
		fi
        if [ $ACT -gt $WRC ];
            then
            WRC=$ACT
        fi
        printf " actions: %-4i" $ACT
        echo ' input: ' $ARG
done
printf "\e[30;103m\tWorst case found: %i ${end}" $WRC

if [ $ERR -eq 0 ];
	then
	printf "${grn}\tSUCCESS [200/200]${end}\n" $ERR
else
	printf "${red}\tFAIL[%i/200] 😱 😱 😱 ${end}\n" $ERR
fi

printf "\n\e[30;103m\tTesting in a range from -50 to 49${end}\n" ####################################
ERR=0
WRC=0
for i in range {1..99}
	do 
		ARG=`ruby -e "puts (-50..49).to_a.shuffle.join(' ')"`
		RET=`./push_swap $ARG | ./checker $ARG`
        ACT=`./push_swap $ARG | wc -l`
		if [ "$RET" != "OK" ];
			then
			((ERR++))
			printf "${red}▓${end}" 
		else
			printf "${grn}▓${end}" 
        fi
        if [ $ACT -gt 700 ];
			then
			((ERR++))
			printf "${red}▓${end}" 
		else
			printf "${grn}▓${end}"
		fi
        if [ $ACT -gt $WRC ];
            then
            WRC=$ACT
        fi
        printf " actions: %-4i\n" $ACT
done
printf "\e[30;103m\tWorst case found: %i ${end}" $WRC

if [ $ERR -eq 0 ];
	then
	printf "${grn}\tSUCCESS [200/200]${end}\n" $ERR
else
	printf "${red}\tFAIL[%i/200] 😱 😱 😱 ${end}\n" $ERR
fi


printf "\n\e[30;103m\tTesting a in a range from -99 to 0${end}\n" ######################################
ERR=0
WRC=0
for i in range {1..99}
	do 
		ARG=`ruby -e "puts (-99..0).to_a.shuffle.join(' ')"`
		RET=`./push_swap $ARG | ./checker $ARG`
        ACT=`./push_swap $ARG | wc -l`
		if [ "$RET" != "OK" ];
			then
			((ERR++))
			printf "${red}▓${end}" 
		else
			printf "${grn}▓${end}" 
        fi
        if [ $ACT -gt 700 ];
			then
			((ERR++))
			printf "${red}▓${end}" 
		else
			printf "${grn}▓${end}"
		fi
        if [ $ACT -gt $WRC ];
            then
            WRC=$ACT
        fi
        printf " actions: %-4i\n" $ACT
done
printf "\e[30;103m\tWorst case found: %i ${end}" $WRC

if [ $ERR -eq 0 ];
	then
	printf "${grn}\tSUCCESS [200/200]${end}\n" $ERR
else
	printf "${red}\tFAIL[%i/200] 😱 😱 😱 ${end}\n" $ERR
fi

printf "\n\e[30;103m\tTesting a in a range from 0 to 99${end}\n" ########################################
ERR=0
WRC=0
for i in range {1..99}
	do 
		ARG=`ruby -e "puts (0..99).to_a.shuffle.join(' ')"`
		RET=`./push_swap $ARG | ./checker $ARG`
        ACT=`./push_swap $ARG | wc -l`
		if [ "$RET" != "OK" ];
			then
			((ERR++))
			printf "${red}▓${end}" 
		else
			printf "${grn}▓${end}" 
        fi
        if [ $ACT -gt 700 ];
			then
			((ERR++))
			printf "${red}▓${end}" 
		else
			printf "${grn}▓${end}"
		fi
        if [ $ACT -gt $WRC ];
            then
            WRC=$ACT
        fi
        printf " actions: %-4i\n" $ACT
done
printf "\e[30;103m\tWorst case found: %i ${end}" $WRC

if [ $ERR -eq 0 ];
	then
	printf "${grn}\tSUCCESS [200/200]${end}\n" $ERR
else
	printf "${red}\tFAIL[%i/200] 😱 😱 😱 ${end}\n" $ERR
fi

printf "\n\e[30;103m\tTesting in a range from 0 to 499${end}\n" ########################################
ERR=0
for i in range {1..99}
	do 
		ARG=`ruby -e "puts (0..499).to_a.shuffle.join(' ')"`
		RET=`./push_swap $ARG | ./checker $ARG`
        ACT=`./push_swap $ARG | wc -l`
		if [ "$RET" != "OK" ];
			then
			((ERR++))
			printf "${red}▓${end}" 
		else
			printf "${grn}▓${end}" 
        fi
        if [ $ACT -gt 5500 ];
			then
			((ERR++))
			printf "${red}▓${end}" 
		else
			printf "${grn}▓${end}"
		fi
        if [ $ACT -gt $WRC ];
            then
            WRC=$ACT
        fi
        printf " actions: %-4i\n" $ACT
done

if [ $ERR -eq 0 ];
	then
	printf "${grn}\tSUCCESS [200/200]${end}\n" $ERR
else
	printf "${red}\tFAIL[%i/200] 😱 😱 😱 ${end}\n" $ERR
fi