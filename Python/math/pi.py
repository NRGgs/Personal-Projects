from math import acos
import sys

def pi_nth_digit(n):
	return round(2 * acos(0.0), n)

if __name__ == "__main__":
	if (len(sys.argv) == 1):
		print("Usage: python calculator <n>")
	else:
		print(pi_nth_digit(int(sys.argv[1])))
