#----------------------
# Bacterie
# ---------------------

rm(list=ls())

library(colorspace)

#----------------------
# p0
# ---------------------
p0 <- read.table("/Users/lisa/Documents/Cours/3-BiM/Projet_DevLog/Bacterie/csv/SM_A017_DT50_PA_PB",sep=";",dec=".")
p02 <- read.table("/Users/lisa/Documents/Cours/3-BiM/Projet_DevLog/Bacterie/csv/a_18_33_pmute0.csv",sep=";",dec=".")

p02 <- p02[1:4]

p0 <- rbind(p0,p02)

names(p0)[names(p0)=="V1"] <- "popB"
names(p0)[names(p0)=="V2"] <- "popA"
names(p0)[names(p0)=="V3"] <- "Trenew"
names(p0)[names(p0)=="V4"] <- "A"

color <- cut(p0$popA, breaks=c(0,0.2,0.5,0.8,1), labels=sequential_hcl(4))

plot(p0$A~p0$Trenew,pch=15,col=color) 

#----------------------
# p0.0001
# ---------------------
rm(list=ls())

library(colorspace)
p00001 <- read.table("/Users/lisa/Documents/Cours/3-BiM/Projet_DevLog/Bacterie/csv/pM_0001_A017_DT50",sep=";",dec=".")
p000012 <- read.table("/Users/lisa/Documents/Cours/3-BiM/Projet_DevLog/Bacterie/csv/a_18_33_pmute00001.csv",sep=";",dec=".")

p000012 <- p000012[1:4]

p00001 <- rbind(p00001,p000012)

names(p00001)[names(p00001)=="V1"] <- "popB"
names(p00001)[names(p00001)=="V2"] <- "popA"
names(p00001)[names(p00001)=="V3"] <- "Trenew"
names(p00001)[names(p00001)=="V4"] <- "A"

color <- cut(p00001$popA, breaks=c(0,0.2,0.5,0.8,1), labels=sequential_hcl(4))

plot(p00001$A~p00001$Trenew,pch=15,col=color) 
