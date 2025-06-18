const pokemonImg = document.getElementById('pokemon-image');
const guessInput = document.getElementById('guess-input');
const submitBtn = document.getElementById('submit-btn');
const nextBtn = document.getElementById('next-btn');

let currentPokemon = null;

function getRandomId() {
    return Math.floor(Math.random() * 250) + 1;
}

async function carregarPokemon() {
    const id = getRandomId();
    const imageUrl = `https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/${id}.png`;
    pokemonImg.src = imageUrl;
    pokemonImg.classList.remove('revealed');

    // Pega o nome do Pokémon via API
    const response = await fetch(`https://pokeapi.co/api/v2/pokemon/${id}`);
    const data = await response.json();
    currentPokemon = data.name.toLowerCase();

    // Habilita input e botão de envio
    guessInput.disabled = false;
    submitBtn.disabled = false;
    nextBtn.disabled = true;
    guessInput.value = '';
}

submitBtn.addEventListener('click', () => {
    const userGuess = guessInput.value.trim().toLowerCase();
    if (userGuess === currentPokemon) {
        pokemonImg.classList.add('revealed');
    }

    // Desativa os inputs
    guessInput.disabled = true;
    submitBtn.disabled = true;
    nextBtn.disabled = false;
});

nextBtn.addEventListener('click', () => {
    carregarPokemon();
});

carregarPokemon();