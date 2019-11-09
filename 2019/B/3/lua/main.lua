local n, urovne, u, k, q, pohyb, mozne_ukoncenia

n = 5

urovne = {
  {-1},
  {1, 1, 1},
  {1, 1, 2, 3, 3, 3, 3},
  {1, 1, 3, 3, 3, 5},
  {2, 2}
}

u = 2 + 1
k = 5
q = 7

pohyb = {"H", "D", "D", "H", "H", "H", "D"}
mozne_ukoncenia = {}

function koniec(u, k)
  for i, ukoncenie in ipairs(mozne_ukoncenia) do
    if ukoncenie[1] == u and ukoncenie[2] == k then
      return
    end
  end
  table.insert(mozne_ukoncenia, {u, k})
end
  

function spocitaj_moznosti(u, k, krok)
  if krok > q then
    koniec(u, k)
    return
  end
  if pohyb[krok] == "H" then
    spocitaj_moznosti(u - 1, urovne[u][k], krok + 1)
  else
    if u + 1 > n then
      koniec(u, k)
      return
    end
    for j, x in ipairs(urovne[u + 1]) do
      if x == k then
        spocitaj_moznosti(u + 1, j, krok + 1)
      end
    end
  end
end

spocitaj_moznosti(u, k, 1)

print(#mozne_ukoncenia)
