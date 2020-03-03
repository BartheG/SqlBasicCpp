import os, fnmatch, sys, shutil

def find(pattern, path):
	result = []
	for root, dirs, files in os.walk(path):
		for name in files:
			if fnmatch.fnmatch(name, pattern):
				result.append(os.path.join(root, name))
	return result

def cleanRepo():
	shutil.rmtree('./build')

def compileBrain():
	print('Compiling: Interactive Shell...')
	os.system("mkdir build && cd build && cmake -G \"Visual Studio 15 2017 Win64\" .. && cmake --build . --config Release && cd ..")
	NameExe = find('interactiveshell.exe', '.\\build')
	if not NameExe:
		cleanRepo()
		return

	shutil.move(NameExe[0], ".\\Release\\interactiveshell.exe")
	cleanRepo()

def deleteExec():
	NameExe = find('interactiveshell.exe', '.')
	if not NameExe:
		print('Already clean')
		return
	os.remove(NameExe[0])

def main():
	if (len(sys.argv) == 2) and sys.argv[1] == "clean":
		deleteExec()
	else:
		compileBrain()
	return 0

if __name__ == "__main__":
	sys.exit(main())