# coding=utf-8
import os
import argparse

SCRIPT_PATH = os.path.split(os.path.realpath(__file__))[0]
SOURCE_DIR_PATH = SCRIPT_PATH + "/.."


def build(system, args=None):
    os.chdir(SOURCE_DIR_PATH)

    # Genearte CMake build files
    if args.release:
        build_cmd = "cmake --preset " + system + "-release"
    else:
        build_cmd = "cmake --preset " + system + "-debug"

    if args.test:
        build_cmd += " -DBUILD_TESTS=ON"

    if args.example:
        build_cmd += " -DBUILD_EXAMPLES=ON"

    print("build cmd:" + build_cmd)

    ret = os.system(build_cmd)
    if ret != 0:
        print("Genearte CMake build files fail!")
        return False

    # Compile project
    build_cmd = "cmake --build build --parallel 8"

    ret = os.system(build_cmd)
    if ret != 0:
        print("Compile project fail!")
        return False

    return True


def main():
    parser = argparse.ArgumentParser(description="build project")
    parser.add_argument(
        "--test", action="store_true", default=False, help="build unit tests"
    )
    parser.add_argument(
        "--example", action="store_true", default=False, help="build examples"
    )
    # parser.add_argument(
    #     "--debug", action="store_true", default=False, help="debug configuration"
    # )
    parser.add_argument(
        "--release", action="store_true", default=False, help="release configuration"
    )
    args = parser.parse_args()

    if os.name == "nt":
        system = "windows"
    elif os.name == "posix":
        system = "linux"
    else:
        print("Unsupported system: " + os.name)
        exit(1)

    if not build(system, args=args):
        exit(1)


if __name__ == "__main__":
    main()
