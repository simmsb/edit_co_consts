from setuptools import Extension, setup

setup(
    name="edit_co_consts",
    version="0.0.1",
    ext_modules=[Extension("edit_co_consts", ["fuck_your_strings.c"])])
