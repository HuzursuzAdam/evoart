from setuptools import find_packages
from setuptools import setup

setup(
    name='evoart_interfaces',
    version='0.0.0',
    packages=find_packages(
        include=('evoart_interfaces', 'evoart_interfaces.*')),
)
