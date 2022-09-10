

import os

path=os.getcwd()
Seuil=6
ValCom=0
ValMar = 0
ValCan = 0
Folder=["Capitaine","Canonnier","Second","QuartierMaitre","MaitreCanonnier","MaitreEquipage"]
ListComp=[]
NewName=""
ListCom=[]
ListMar=[]
ListCan=[]
ComsCan=["Ballistique","Tactique","Pointage","Recharge"]
ComsMarin=["Cartographie","ConnaissancesNautiques","Hydrographie","PratiqueNautique","Timonerie"]
Coms=["Empathie","Intimidation","Persuasion","Meneur","Enseignement"]
for fold in Folder:
    Npath=os.path.join(path,fold)
    for fic in os.listdir(Npath):

        os.remove(os.path.join(Npath,fic))



