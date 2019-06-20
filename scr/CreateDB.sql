-- Таблица Клиенты
CREATE TABLE [dbo].[Client]
(
	[Id] INT NOT NULL PRIMARY KEY, 
    [Name] VARCHAR(50) NOT NULL, 
    [Surname] VARCHAR(50) NOT NULL, 
    [BirthDay] DATE NULL, 
    [RegDate] DATE NOT NULL, 
    [Phone] VARCHAR(11) NOT NULL, 
    [Email] VARCHAR(255) NULL, 
    CONSTRAINT [AK_Client_Column] UNIQUE ([Surname], [Phone])
)

-- Таблица Парикмахеры
CREATE TABLE [dbo].[Hairdresser]
(
	[Id] INT NOT NULL PRIMARY KEY, 
    [Name] VARCHAR(50) NOT NULL, 
    [Surname] VARCHAR(50) NOT NULL, 
    [Phone] VARCHAR(11) NOT NULL, 
    CONSTRAINT [AK_Hairdresser_Column] UNIQUE ([Name], [Surname], [Phone])
)

-- Таблица записей
CREATE TABLE [dbo].[RcordOrder]
(
	[Id] INT NOT NULL PRIMARY KEY, 
    [HairdresserId] INT NOT NULL, 
    [ClientId] INT NOT NULL, 
    [HaircutId] INT NOT NULL, 
    [Date] DATETIME NOT NULL,  
    CONSTRAINT [AK_RcordOrder_Column] UNIQUE ([HairdresserId], [ClientId], [Date]), 
	CONSTRAINT [FK_RcordOrder_Client] FOREIGN KEY ([ClientId]) REFERENCES [Client]([Id]), 
	CONSTRAINT [FK_RcordOrder_Hairdresser] FOREIGN KEY ([HairdresserId]) REFERENCES [Hairdresser]([Id]), 
    CONSTRAINT [FK_RcordOrder_Haircut] FOREIGN KEY ([HaircutId]) REFERENCES [Haircut]([Id])
)

-- Таблица стрижки
CREATE TABLE [dbo].[Haircut]
(
	[Id] INT NOT NULL PRIMARY KEY, 
    [Name] VARCHAR(50) NOT NULL, 
    [Price] NUMERIC NOT NULL
)

-- http://www.kors-soft.ru/instr/sal3/instr.htm