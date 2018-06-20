#----------------------
# Bacterie
# ---------------------

rm(list=ls())

#----------------------
# p0
# ---------------------
p0 <- read.table("/Users/lisa/Documents/Cours/3-BiM/Projet_DevLog/Bacterie/csv/SM_A017_DT50_PA_PB",sep=";",dec=".")
p02 <- read.table("/Users/lisa/Documents/Cours/3-BiM/Projet_DevLog/Bacterie/csv/a_18_33_pmute0.csv",sep=";",dec=".")
p03 <- read.table("/Users/lisa/Documents/Cours/3-BiM/Projet_DevLog/Bacterie/csv/mut34a50.csv",sep=";",dec=".")

p02 <- p02[1:4]

p03 <- p03[p03$V5==0.1,]
p03 <- p03[1:4]
  
p0 <- rbind(p0,p02)
p0 <- rbind(p0,p03)

names(p0)[names(p0)=="V1"] <- "popB"
names(p0)[names(p0)=="V2"] <- "popA"
names(p0)[names(p0)=="V3"] <- "Trenew"
names(p0)[names(p0)=="V4"] <- "A"

extinction = (p0$popB == 0 & p0$popA == 0)
exclusion = (p0$popB== 0 & p0$popA != 0) 
exclusion_elargie = (p0$popB < 0.1*p0$popA & p0$popA != 0) 
cohabitation = (p0$popB != 0 & p0$popA != 0)

plot(p0$A[extinction]~p0$Trenew[extinction],
     pch=15,col='red',ylim=c(0,70),
     main="Etat final de la population pour p(mute) = 0",
     xlab='T',ylab = 'A(init)')
points(p0$A[cohabitation]~p0$Trenew[cohabitation],pch=15,col='green')
points(p0$A[exclusion_elargie]~p0$Trenew[exclusion_elargie],pch=15,col='yellow')
points(p0$A[exclusion]~p0$Trenew[exclusion],pch=15,col='orange')
legend('topright',col=c('red','orange','yellow','green'),pch=c(15,15,15,15),legend=c('Extinction','Exclusion','Exclusion élargie','Cohabitation'),ncol = 2)

#----------------------
# p = 0.0001
# ---------------------
rm(list=ls())

p00001 <- read.table("/Users/lisa/Documents/Cours/3-BiM/Projet_DevLog/Bacterie/csv/pM_0001_A017_DT50",sep=";",dec=".")
p000012 <- read.table("/Users/lisa/Documents/Cours/3-BiM/Projet_DevLog/Bacterie/csv/a_18_33_pmute00001.csv",sep=";",dec=".")
p000013 <- read.table("/Users/lisa/Documents/Cours/3-BiM/Projet_DevLog/Bacterie/csv/mut34a50.csv",sep=";",dec=".")


p000012 <- p000012[1:4]

# Select data in D
p000013 <- p000013[p000013$V5==0.1,]
p000013 <- p000013[1:4]

p00001 <- rbind(p00001,p000012)
p00001 <- rbind(p00001,p000013)

names(p00001)[names(p00001)=="V1"] <- "popB"
names(p00001)[names(p00001)=="V2"] <- "popA"
names(p00001)[names(p00001)=="V3"] <- "Trenew"
names(p00001)[names(p00001)=="V4"] <- "A"

extinction = (p00001$popB == 0 & p00001$popA == 0)
exclusion = (p00001$popB== 0 & p00001$popA != 0) 
exclusion_elargie = (p00001$popB < 0.1*p00001$popA & p00001$popA != 0) 
cohabitation = (p00001$popB != 0 & p00001$popA != 0)

plot(p00001$A[extinction]~p00001$Trenew[extinction],pch=15,col='red',ylim=c(0,70),
     main="Etat final de la population pour p(mute)=0.0001",
     xlab='T',ylab = 'A(init)')
points(p00001$A[cohabitation]~p00001$Trenew[cohabitation],pch=15,col='green')
points(p00001$A[exclusion_elargie]~p00001$Trenew[exclusion_elargie],pch=15,col='yellow')
points(p00001$A[exclusion]~p00001$Trenew[exclusion],pch=15,col='orange')
legend('topright',col=c('red','orange','yellow','green'),pch=c(15,15,15,15),legend=c('Extinction','Exclusion','Exclusion élargie','Cohabitation'),ncol = 2)

