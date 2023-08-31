import random

class Villain:
    def __init__(self, name):
        self.name = name
        self.health = 100
        self.energy = 500
        self.shield = 0

    def damage(self, weapon):
        if self.shield > 0:
            reduced_damage = weapon.damage * (1 - self.shield / 100)
            self.health -= reduced_damage
        else:
            self.health -= weapon.damage

    def use_shield(self):
        self.shield = random.randint(10, 30)

class Weapon:
    def __init__(self, name, energy, damage):
        self.name = name
        self.energy = energy
        self.damage = damage

class Gru:
    def __init__(self):
        self.weapons = [
            Weapon("Freeze Gun", 50, 10),
            Weapon("Electric Prod", 88, 18),
            Weapon("Mega Magnet", 92, 20),
            Weapon("Kalman Missile", 120, 11)
        ]
        self.shields = [
            Weapon("Energy-Projected Barrier Gun", 20, 40),
            Weapon("Selective Permeability", 50, 90)
        ]

class Vector:
    def __init__(self):
        self.weapons = [
            Weapon("Laser Blasters", 40, 13),
            Weapon("Plasma Grenades", 8, 22),
            Weapon("Sonic Resonance Cannon", 100, 8)
        ]
        self.shields = [
            Weapon("Energy Net Trap", 15, 32),
            Weapon("Quantum Deflector", 40, 80)
        ]

def play_game():
    gru = Gru()
    vector = Vector()

    gru_villain = Villain("Gru")
    vector_villain = Villain("Vector")

    while gru_villain.health > 0 and vector_villain.health > 0:
        gru_weapon = random.choice(gru.weapons)
        vector_weapon = random.choice(vector.weapons)

        gru_villain.damage(vector_weapon)
        vector_villain.damage(gru_weapon)

        if gru_villain.health <= 0 or vector_villain.health <= 0:
            break

        gru_villain.use_shield()
        vector_villain.use_shield()

    if gru_villain.health <= 0:
        print("Vector wins!")
    else:
        print("Gru wins!")

play_game()