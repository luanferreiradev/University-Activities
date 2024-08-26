const axios = require('axios');
const cheerio = require('cheerio');
const schedule = require('node-schedule');

// URL do site de empregos que você quer rastrear
const url = 'https://www.exemplo.com/empregos';

// Função para buscar e extrair informações de emprego
async function buscarEmpregos() {
    try {
        const { data } = await axios.get(url);
        const $ = cheerio.load(data);

        // Exemplo de extração: buscando títulos de vagas
        const empregos = [];
        $('.job-title').each((i, element) => {
            const titulo = $(element).text().trim();
            empregos.push(titulo);
        });

        console.log('Empregos encontrados:', empregos);
    } catch (error) {
        console.error('Erro ao buscar empregos:', error.message);
    }
}

// Agendar a execução do rastreamento a cada hora
schedule.scheduleJob('0 * * * *', buscarEmpregos);

// Executar imediatamente ao iniciar o script
buscarEmpregos();
