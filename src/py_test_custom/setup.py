from setuptools import find_packages, setup

package_name = 'py_test_custom'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='lasantha',
    maintainer_email='lasantha@todo.todo',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
                'custom_pub = py_test_custom.custom_msg_publisher:main',
                'custom_sub = py_test_custom.custom_msg_subscriber:main',
        ],
    },
)
