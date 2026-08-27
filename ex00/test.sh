#!/bin/bash
# ─────────────────────────────────────────────────────────────────────────────
# test.sh – Functional tests for ex00
# ─────────────────────────────────────────────────────────────────────────────

GREEN='\033[0;32m'
RED='\033[0;31m'
BOLD='\033[1m'
NC='\033[0m'

BINARY="./whatever"

PASS=0
FAIL=0

assert_eq() {
    local description="$1"
    local expected="$2"
    local actual="$3"

    if [ "$actual" = "$expected" ]; then
        echo -e "${GREEN}[OK]${NC} $description"
        PASS=$((PASS + 1))
    else
        echo -e "${RED}[KO]${NC} $description"
        echo -e "   ${BOLD}Expected:${NC}\n$expected"
        echo -e "   ${BOLD}Got:     ${NC}\n$actual"
        FAIL=$((FAIL + 1))
    fi
}

echo -e "\n${BOLD}══════════════════════════════════════════${NC}"
echo -e "${BOLD}  Testing ex00${NC}"
echo -e "${BOLD}══════════════════════════════════════════${NC}\n"

make > /dev/null 2>&1
if [ ! -f "$BINARY" ]; then
    echo -e "${RED}Build failed – cannot run tests.${NC}"
    exit 1
fi

# The subject requires this exact output
EXPECTED_OUTPUT="a = 3, b = 2
min(a, b) = 2
max(a, b) = 3
c = chaine2, d = chaine1
min(c, d) = chaine1
max(c, d) = chaine2"

ACTUAL=$($BINARY)

assert_eq "Output perfectly matches the subject requirements" "$EXPECTED_OUTPUT" "$ACTUAL"

echo ""
echo -e "${BOLD}══════════════════════════════════════════${NC}"
TOTAL=$((PASS + FAIL))
if [ "$FAIL" -eq 0 ]; then
    echo -e "${GREEN}${BOLD}  ✔ $PASS/$TOTAL tests passed${NC}"
else
    echo -e "${RED}${BOLD}  ✘ $FAIL/$TOTAL tests FAILED${NC}"
fi
echo -e "${BOLD}══════════════════════════════════════════${NC}\n"

[ "$FAIL" -eq 0 ]
