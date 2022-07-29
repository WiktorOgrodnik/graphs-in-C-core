import os
import subprocess
import sys

cases = [
	("2.5", "2.500000"),
	("(2x + 5) - 10", "-3.000000"),
	("(3x + 5) - 10", "-2.000000"),
	("(3*x + 5) - 10", "-2.000000"),
	("(3 * x + 5) - 10", "-2.000000"),
	("sin(x) + 5", "5.841471"),
	("log(10)", "2.302585"),
	("2 + 2", "4.000000"),
	("2x", "2.000000"),
	("4x", "4.000000"),
	("4e", "10.873127"),
	("4*e", "10.873127"),
	("(4e)", "10.873127"),
	("(4*e )", "10.873127"),
	("e", "2.718282"),
]

executable = "./math.exe"

if not os.access(executable, os.R_OK):
	print("./math.exe does not exist!")
	quit()

if not os.access(executable, os.X_OK):
	print("math.exe does not exists!")
	quit()

for it, (test_case, expected_output) in enumerate(cases):

	print('Test case {}: '.format(it + 1), end='')

	p = subprocess.run([executable], stdout=subprocess.PIPE, input=test_case, encoding='ascii')
	if p.returncode != 0:
		print("⛔ Program returned non zero exit code!")
		continue
	
	test_output = p.stdout.strip()
	if test_output == 'Result: ' + expected_output:
		print("✅ Success!")
	else:
		print("⛔ Expected {}, returned {}".format(expected_output, test_output))
  

