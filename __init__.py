import os
from xml.dom import NotFoundErr
if os.path.exists(os.path.join(os.path.dirname(__file__), 'bin/Lass.so')):
    from .bin.Lass import Lass
else:
    raise NotFoundErr('Lass is not compiled')