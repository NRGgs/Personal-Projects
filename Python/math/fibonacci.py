import sys

def fibonacci(n):
	return n if n <= 1 else fibonacci(n - 1) + fibonacci(n - 2)

if __name__ == "__main__":
	if (len(sys.argv) == 1):
		print("Usage: python calculator <n>")
	else:
		print(fibonacci(int(sys.argv[1])))
