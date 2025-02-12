/*
 * This file is part of the Monero P2Pool <https://github.com/SChernykh/p2pool>
 * Copyright (c) 2021 SChernykh <https://github.com/SChernykh>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "common.h"
#include "params.h"

namespace p2pool {

Params::Params(int argc, char* argv[])
{
	for (int i = 1; i < argc; ++i) {
		if ((strcmp(argv[i], "--host") == 0) && (i + 1 < argc)) {
			m_host = argv[++i];
		}

		if ((strcmp(argv[i], "--rpc-port") == 0) && (i + 1 < argc)) {
			m_rpcPort = static_cast<uint32_t>(atoi(argv[++i]));
		}

		if ((strcmp(argv[i], "--zmq-port") == 0) && (i + 1 < argc)) {
			m_zmqPort = static_cast<uint32_t>(atoi(argv[++i]));
		}

		if (strcmp(argv[i], "--light-mode") == 0) {
			m_lightMode = true;
		}

		if ((strcmp(argv[i], "--wallet") == 0) && (i + 1 < argc)) {
			m_wallet.decode(argv[++i]);
		}

		if ((strcmp(argv[i], "--stratum") == 0) && (i + 1 < argc)) {
			m_stratumAddresses = argv[++i];
		}

		if ((strcmp(argv[i], "--p2p") == 0) && (i + 1 < argc)) {
			m_p2pAddresses = argv[++i];
		}

		if ((strcmp(argv[i], "--addpeers") == 0) && (i + 1 < argc)) {
			m_p2pPeerList = argv[++i];
		}

		if ((strcmp(argv[i], "--loglevel") == 0) && (i + 1 < argc)) {
			const int level = std::min(std::max(atoi(argv[++i]), 0), 5);
			log::GLOBAL_LOG_LEVEL = level;
		}

		if ((strcmp(argv[i], "--config") == 0) && (i + 1 < argc)) {
			m_config = argv[++i];
		}
	}
}

bool Params::ok() const
{
	return m_host && m_rpcPort && m_zmqPort && m_wallet.valid();
}

} // namespace p2pool
