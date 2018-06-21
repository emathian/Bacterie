d <- read.table("./csv/chr/30_300_pm02.csv",sep=";",dec=".")

names(d)[names(d)=="V1"] <- "T"
names(d)[names(d)=="V2"] <- "popB"
names(d)[names(d)=="V3"] <- "popA"

plot(d$popA~d$T,col='red',
     main='Populations A et B en fonction du temps',
     xlab='Temps',ylab='Individus',type='l')
lines(d$popB~d$T,col='blue',type='l')
legend('topright',col=c('red','blue'),legend=c('A','B'),lty=c(1,1))

