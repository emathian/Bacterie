
rm(list=ls())
d <- read.table("/Users/lisa/Documents/Cours/3-BiM/Projet_DevLog/Bacterie/csv/chr/30_700_pm0.csv",sep=";",dec=".")
d2 <- read.table("/Users/lisa/Documents/Cours/3-BiM/Projet_DevLog/Bacterie/csv/chr/30_700_pm02.csv",sep=";",dec=".")
d3 <- read.table("/Users/lisa/Documents/Cours/3-BiM/Projet_DevLog/Bacterie/csv/chr/30_700_pm03.csv",sep=";",dec=".")


names(d)[names(d)=="V1"] <- "T"
names(d)[names(d)=="V2"] <- "popB"
names(d)[names(d)=="V3"] <- "popA"

names(d2)[names(d2)=="V1"] <- "T"
names(d2)[names(d2)=="V2"] <- "popB"
names(d2)[names(d2)=="V3"] <- "popA"

names(d3)[names(d3)=="V1"] <- "T"
names(d3)[names(d3)=="V2"] <- "popB"
names(d3)[names(d3)=="V3"] <- "popA"

plot(d$popA[0:4999]~d$T[0:4999],col='red',
     main='Populations A et B en fonction du temps',
     xlab='Temps',ylab='Individus',type='l')
lines(d$popB[0:4999]~d$T[0:4999],col='blue',type='l')
lines(d2$popA~d2$T,col='red',type='l')
lines(d2$popB~d2$T,col='blue',type='l')
lines(d3$popA~d3$T,col='red',type='l')
lines(d3$popB~d3$T,col='blue',type='l')
legend('bottomright',col=c('red','blue'),legend=c('A','B'),lty=c(1,1))


