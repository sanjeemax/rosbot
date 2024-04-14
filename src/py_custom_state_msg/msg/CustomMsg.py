# CustomMsg.py

from typing import Optional
from typing_extensions import Annotated
from pydantic import BaseModel

class CustomMsg(BaseModel):
    err:Annotated[float, "Error between center and dot"]
    linear_x: Annotated[float, "Linear velocity along the x-axis"]
    linear_y: Annotated[float, "Linear velocity along the y-axis"]
    linear_z: Annotated[float, "Linear velocity along the z-axis"]
    angular_x: Annotated[float, "Angular velocity around the x-axis"]
    angular_y: Annotated[float, "Angular velocity around the y-axis"]
    angular_z: Annotated[float, "Angular velocity around the z-axis"]
