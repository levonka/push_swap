# turn off printf in issorted.c

rm res

hel=$(./script.sh 1 5 100 | awk '{suma += $1}END{print suma}' | awk '{heh = $1/100}'END'{print heh}')
echo "5 el, 100 times = $hel\n" > res
hel=$(./script.sh 1 10 100 | awk '{suma += $1}END{print suma}' | awk '{heh = $1/100}'END'{print heh}')
echo "10 el, 100 times = $hel\n" >> res
hel=$(./script.sh 1 20 100 | awk '{suma += $1}END{print suma}' | awk '{heh = $1/100}'END'{print heh}')
echo "20 el, 100 times = $hel\n" >> res
hel=$(./script.sh 1 50 100 | awk '{suma += $1}END{print suma}' | awk '{heh = $1/100}'END'{print heh}')
echo "50 el, 100 times = $hel\n" >> res
hel=$(./script.sh 1 100 100 | awk '{suma += $1}END{print suma}' | awk '{heh = $1/100}'END'{print heh}')
echo "100 el, 100 times = $hel\n" >> res
hel=$(./script.sh 1 200 50 | awk '{suma += $1}END{print suma}' | awk '{heh = $1/50}'END'{print heh}')
echo "200 el, 50 times = $hel\n" >> res
hel=$(./script.sh 1 500 30 | awk '{suma += $1}END{print suma}' | awk '{heh = $1/30}'END'{print heh}')
echo "500 el, 30 times = $hel\n" >> res