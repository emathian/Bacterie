d <- read.table("/Users/lisa/Documents/Cours/3-BiM/Projet_DevLog/Bacterie/csv/chr/22_1700_pm0.csv",sep=";",dec=".")


names(d)[names(d)=="V1"] <- "T"
names(d)[names(d)=="V2"] <- "popB"
names(d)[names(d)=="V3"] <- "popA"

plot(d$popA[0:4999],d$popB[0:4999],
     main='Chroniques de A et B',
     type='l',
     xlab='A',ylab='B')


