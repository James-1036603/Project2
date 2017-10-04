##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Game_Project
ConfigurationName      :=Debug
WorkspacePath          :=C:/Users/DrDoom/Documents/Project
ProjectPath            :=C:/Users/DrDoom/Documents/Project/Game_Project
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=DrDoom
Date                   :=04/10/2017
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :=C:/TDM-GCC-64/bin/g++.exe
SharedObjectLinkerName :=C:/TDM-GCC-64/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="Game_Project.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/TDM-GCC-64/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)C:\SFML\include $(IncludeSwitch)C:\Users\DrDoom\Documents\Default\doctest 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)sfml-audio $(LibrarySwitch)sfml-graphics $(LibrarySwitch)sfml-window $(LibrarySwitch)sfml-system 
ArLibs                 :=  "sfml-audio" "sfml-graphics" "sfml-window" "sfml-system" 
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)C:\SFML\lib 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/TDM-GCC-64/bin/ar.exe rcu
CXX      := C:/TDM-GCC-64/bin/g++.exe -std=c++14
CC       := C:/TDM-GCC-64/bin/gcc.exe
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/TDM-GCC-64/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/Bullet.cpp$(ObjectSuffix) $(IntermediateDirectory)/BulletManager.cpp$(ObjectSuffix) $(IntermediateDirectory)/Draw.cpp$(ObjectSuffix) $(IntermediateDirectory)/Enemy.cpp$(ObjectSuffix) $(IntermediateDirectory)/EnemyManager.cpp$(ObjectSuffix) $(IntermediateDirectory)/EnemyMovement.cpp$(ObjectSuffix) $(IntermediateDirectory)/Engine.cpp$(ObjectSuffix) $(IntermediateDirectory)/GameMusic.cpp$(ObjectSuffix) $(IntermediateDirectory)/Include.cpp$(ObjectSuffix) $(IntermediateDirectory)/Level.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/Player.cpp$(ObjectSuffix) $(IntermediateDirectory)/PlayerManager.cpp$(ObjectSuffix) $(IntermediateDirectory)/Update.cpp$(ObjectSuffix) $(IntermediateDirectory)/GameTests.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/Bullet.cpp$(ObjectSuffix): Bullet.cpp $(IntermediateDirectory)/Bullet.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/DrDoom/Documents/Project/Game_Project/Bullet.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Bullet.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Bullet.cpp$(DependSuffix): Bullet.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Bullet.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Bullet.cpp$(DependSuffix) -MM Bullet.cpp

$(IntermediateDirectory)/Bullet.cpp$(PreprocessSuffix): Bullet.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Bullet.cpp$(PreprocessSuffix) Bullet.cpp

$(IntermediateDirectory)/BulletManager.cpp$(ObjectSuffix): BulletManager.cpp $(IntermediateDirectory)/BulletManager.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/DrDoom/Documents/Project/Game_Project/BulletManager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/BulletManager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/BulletManager.cpp$(DependSuffix): BulletManager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/BulletManager.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/BulletManager.cpp$(DependSuffix) -MM BulletManager.cpp

$(IntermediateDirectory)/BulletManager.cpp$(PreprocessSuffix): BulletManager.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/BulletManager.cpp$(PreprocessSuffix) BulletManager.cpp

$(IntermediateDirectory)/Draw.cpp$(ObjectSuffix): Draw.cpp $(IntermediateDirectory)/Draw.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/DrDoom/Documents/Project/Game_Project/Draw.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Draw.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Draw.cpp$(DependSuffix): Draw.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Draw.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Draw.cpp$(DependSuffix) -MM Draw.cpp

$(IntermediateDirectory)/Draw.cpp$(PreprocessSuffix): Draw.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Draw.cpp$(PreprocessSuffix) Draw.cpp

$(IntermediateDirectory)/Enemy.cpp$(ObjectSuffix): Enemy.cpp $(IntermediateDirectory)/Enemy.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/DrDoom/Documents/Project/Game_Project/Enemy.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Enemy.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Enemy.cpp$(DependSuffix): Enemy.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Enemy.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Enemy.cpp$(DependSuffix) -MM Enemy.cpp

$(IntermediateDirectory)/Enemy.cpp$(PreprocessSuffix): Enemy.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Enemy.cpp$(PreprocessSuffix) Enemy.cpp

$(IntermediateDirectory)/EnemyManager.cpp$(ObjectSuffix): EnemyManager.cpp $(IntermediateDirectory)/EnemyManager.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/DrDoom/Documents/Project/Game_Project/EnemyManager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/EnemyManager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/EnemyManager.cpp$(DependSuffix): EnemyManager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/EnemyManager.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/EnemyManager.cpp$(DependSuffix) -MM EnemyManager.cpp

$(IntermediateDirectory)/EnemyManager.cpp$(PreprocessSuffix): EnemyManager.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/EnemyManager.cpp$(PreprocessSuffix) EnemyManager.cpp

$(IntermediateDirectory)/EnemyMovement.cpp$(ObjectSuffix): EnemyMovement.cpp $(IntermediateDirectory)/EnemyMovement.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/DrDoom/Documents/Project/Game_Project/EnemyMovement.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/EnemyMovement.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/EnemyMovement.cpp$(DependSuffix): EnemyMovement.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/EnemyMovement.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/EnemyMovement.cpp$(DependSuffix) -MM EnemyMovement.cpp

$(IntermediateDirectory)/EnemyMovement.cpp$(PreprocessSuffix): EnemyMovement.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/EnemyMovement.cpp$(PreprocessSuffix) EnemyMovement.cpp

$(IntermediateDirectory)/Engine.cpp$(ObjectSuffix): Engine.cpp $(IntermediateDirectory)/Engine.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/DrDoom/Documents/Project/Game_Project/Engine.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Engine.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Engine.cpp$(DependSuffix): Engine.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Engine.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Engine.cpp$(DependSuffix) -MM Engine.cpp

$(IntermediateDirectory)/Engine.cpp$(PreprocessSuffix): Engine.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Engine.cpp$(PreprocessSuffix) Engine.cpp

$(IntermediateDirectory)/GameMusic.cpp$(ObjectSuffix): GameMusic.cpp $(IntermediateDirectory)/GameMusic.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/DrDoom/Documents/Project/Game_Project/GameMusic.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/GameMusic.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/GameMusic.cpp$(DependSuffix): GameMusic.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/GameMusic.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/GameMusic.cpp$(DependSuffix) -MM GameMusic.cpp

$(IntermediateDirectory)/GameMusic.cpp$(PreprocessSuffix): GameMusic.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/GameMusic.cpp$(PreprocessSuffix) GameMusic.cpp

$(IntermediateDirectory)/Include.cpp$(ObjectSuffix): Include.cpp $(IntermediateDirectory)/Include.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/DrDoom/Documents/Project/Game_Project/Include.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Include.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Include.cpp$(DependSuffix): Include.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Include.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Include.cpp$(DependSuffix) -MM Include.cpp

$(IntermediateDirectory)/Include.cpp$(PreprocessSuffix): Include.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Include.cpp$(PreprocessSuffix) Include.cpp

$(IntermediateDirectory)/Level.cpp$(ObjectSuffix): Level.cpp $(IntermediateDirectory)/Level.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/DrDoom/Documents/Project/Game_Project/Level.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Level.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Level.cpp$(DependSuffix): Level.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Level.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Level.cpp$(DependSuffix) -MM Level.cpp

$(IntermediateDirectory)/Level.cpp$(PreprocessSuffix): Level.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Level.cpp$(PreprocessSuffix) Level.cpp

$(IntermediateDirectory)/Player.cpp$(ObjectSuffix): Player.cpp $(IntermediateDirectory)/Player.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/DrDoom/Documents/Project/Game_Project/Player.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Player.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Player.cpp$(DependSuffix): Player.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Player.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Player.cpp$(DependSuffix) -MM Player.cpp

$(IntermediateDirectory)/Player.cpp$(PreprocessSuffix): Player.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Player.cpp$(PreprocessSuffix) Player.cpp

$(IntermediateDirectory)/PlayerManager.cpp$(ObjectSuffix): PlayerManager.cpp $(IntermediateDirectory)/PlayerManager.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/DrDoom/Documents/Project/Game_Project/PlayerManager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/PlayerManager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/PlayerManager.cpp$(DependSuffix): PlayerManager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/PlayerManager.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/PlayerManager.cpp$(DependSuffix) -MM PlayerManager.cpp

$(IntermediateDirectory)/PlayerManager.cpp$(PreprocessSuffix): PlayerManager.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/PlayerManager.cpp$(PreprocessSuffix) PlayerManager.cpp

$(IntermediateDirectory)/Update.cpp$(ObjectSuffix): Update.cpp $(IntermediateDirectory)/Update.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/DrDoom/Documents/Project/Game_Project/Update.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Update.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Update.cpp$(DependSuffix): Update.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Update.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Update.cpp$(DependSuffix) -MM Update.cpp

$(IntermediateDirectory)/Update.cpp$(PreprocessSuffix): Update.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Update.cpp$(PreprocessSuffix) Update.cpp

$(IntermediateDirectory)/GameTests.cpp$(ObjectSuffix): GameTests.cpp $(IntermediateDirectory)/GameTests.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/DrDoom/Documents/Project/Game_Project/GameTests.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/GameTests.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/GameTests.cpp$(DependSuffix): GameTests.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/GameTests.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/GameTests.cpp$(DependSuffix) -MM GameTests.cpp

$(IntermediateDirectory)/GameTests.cpp$(PreprocessSuffix): GameTests.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/GameTests.cpp$(PreprocessSuffix) GameTests.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


