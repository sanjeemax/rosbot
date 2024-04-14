from setuptools import find_packages, setup

package_name = 'py_2wbot_ctrl'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        #(os.path.join('share', package_name), glob('launch/*.launch.py')),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='lasantha',
    maintainer_email='lasantha.vsolve@gmail.com',
    description='TODO: Package description',
    license='Apache License 2.0',
    tests_require=['pytest'],
    entry_points={
            'console_scripts': [
                'follower_node = py_2wbot_ctrl.follower_node:main',
                #'recorder = py_2wbot_ctrl.recorder:main',
                'odom_rd = py_2wbot_ctrl.odom_rd:main',
                'pilco_node = py_2wbot_ctrl.pilco_node:main',
                #'controller = py_2wbot_ctrl.publisher_member_function:main',
                #'imgrecord = py_2wbot_ctrl.subscriber_member_function:main',
            ],
    },
)
